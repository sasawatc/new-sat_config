#include "satconfigsys.h"


#include <QDebug>

SatConfigSys::SatConfigSys(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow main_window;
    main_window.show();

    data_model = new QStandardItemModel(0, 6, &main_window);
    initDataModel();
    importSatConfig(SAT_CONFIG_PATH);


    scc_proxyModel = new QSortFilterProxyModel(&main_window);
    mpc_pl_proxyModel = new QSortFilterProxyModel(&main_window);
    mpc_aocs_proxyModel = new QSortFilterProxyModel(&main_window);
    fds_proxyModel = new QSortFilterProxyModel(&main_window);

    scc_proxyModel->setFilterFixedString(SCC_STR);
    mpc_pl_proxyModel->setFilterFixedString(MPC_PL_STR);
    mpc_aocs_proxyModel->setFilterFixedString(MPC_AOCS_STR);
    fds_proxyModel->setFilterFixedString(FDS_STR);

    scc_proxyModel->setSourceModel(data_model);
    mpc_pl_proxyModel->setSourceModel(data_model);
    mpc_aocs_proxyModel->setSourceModel(data_model);
    fds_proxyModel->setSourceModel(data_model);

    stations = getStationsFromMpcPl();
    satellites = getSatellitesFromMpcPl();

    main_window.setModel(scc_proxyModel, mpc_pl_proxyModel, mpc_aocs_proxyModel, fds_proxyModel);
    main_window.createButtons(scc_proxyModel, mpc_pl_proxyModel, mpc_aocs_proxyModel, fds_proxyModel, stations, satellites);

    connect(&main_window, SIGNAL(transferFilesClicked()),this,SLOT(onTransferFilesClicked()));
    connect(&main_window, SIGNAL(saveToConfSatClicked()),this,SLOT(onSaveToConfSatClicked()));


    app.exec();
}

SatConfigSys::~SatConfigSys()
{

}
void SatConfigSys::importSatConfig(QString filepath)
{
    QFile sat_config_file(filepath);
    if(!sat_config_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",sat_config_file.errorString());
    }
    QTextStream in_stream(&sat_config_file);

    while(!in_stream.atEnd())
    {
        QString in_str = in_stream.readLine();

        QStringList param_list = in_str.split(" ", QString::SkipEmptyParts);

        QList<QStandardItem *> param_item_list;

        param_item_list.append(new QStandardItem(param_list.at(GROUPS_FILE_INDEX)));
        param_item_list.append(new QStandardItem(param_list.at(NAME_FILE_INDEX)));
        param_item_list.append(new QStandardItem(param_list.at(VALUE_FILE_INDEX)));
        param_item_list.append(new QStandardItem()); //new value
        param_item_list.append(new QStandardItem(param_list.at(TYPE_FILE_INDEX)));
        param_item_list.append(new QStandardItem(param_list.at(NOTE_FILE_INDEX)));
        param_item_list.append(new QStandardItem(param_list.at(TYPE_UNIT_FILE_INDEX)));

        //Disable editing in all field except for "New Value" column
        for(int i = 0; i < param_item_list.count(); i++)
        {
            if(i != VALUE_NEW_INDEX)
            {
                param_item_list[i]->setFlags(param_item_list[i]->flags() & ~Qt::ItemIsEditable);
            }
        }

        data_model->appendRow(param_item_list);
    }
}

void SatConfigSys::initDataModel()
{
    data_model->setHorizontalHeaderItem(GROUPS_INDEX, new QStandardItem(QString("Groups")));
    data_model->setHorizontalHeaderItem(NAME_INDEX, new QStandardItem(QString("Parameter Name")));
    data_model->setHorizontalHeaderItem(VALUE_INDEX, new QStandardItem(QString("Old Value")));
    data_model->setHorizontalHeaderItem(VALUE_NEW_INDEX, new QStandardItem(QString("New Value")));
    data_model->setHorizontalHeaderItem(TYPE_INDEX, new QStandardItem(QString("Type")));
    data_model->setHorizontalHeaderItem(NOTE_INDEX, new QStandardItem(QString("Note")));
}

QList<Station *> * SatConfigSys::getStationsFromMpcPl()
{
    QList<Station *> *stations = new QList<Station *>;

//    const int STARTING_ROW = 1; //First row of actual data in model_MPC_PL, row 0 is XML version number
//    bool b_active = true;
//    int current_row = STARTING_ROW;
//    int ciphering_key_iter = 0;

//    while(b_active)
//    {
//        b_active = false;
//        QModelIndex name_index = mpc_pl_proxyModel->index(current_row, NAME_INDEX);

//        if(mpc_pl_proxyModel->data(name_index).toString() == "staName")
//        {
//            QModelIndex station_name_index = mpc_pl_proxyModel->index(current_row, VALUE_INDEX);
//            stations->append(new Station());
//            stations->last()->name_index = station_name_index;
//            ciphering_key_iter = 0;
//            b_active = true;
//        }
//        else if(mpc_pl_proxyModel->data(name_index).toString().contains("CipheringKey"))
//        {
//            QModelIndex ciphering_key = mpc_pl_proxyModel->index(current_row, VALUE_INDEX);
//            stations->last()->ciphering_keys_index.append(ciphering_key);
//            ciphering_key_iter++;
//            b_active = true;
//        }
//        current_row++;
//    }
//    return stations;

    for(int current_row = 0; current_row < mpc_pl_proxyModel->rowCount(); current_row++)
    {
        QModelIndex name_index = mpc_pl_proxyModel->index(current_row, NAME_INDEX);

        if(mpc_pl_proxyModel->data(name_index).toString() == "staName")
        {
            QModelIndex station_name_index = mpc_pl_proxyModel->index(current_row, VALUE_INDEX);
            stations->append(new Station());
            stations->last()->name_index = station_name_index;
        }
        else if(mpc_pl_proxyModel->data(name_index).toString().contains("CipheringKey"))
        {
            QModelIndex ciphering_key_index = mpc_pl_proxyModel->index(current_row, VALUE_INDEX);
            stations->last()->ciphering_keys_index.append(ciphering_key_index);
        }
    }
    return stations;
}

QList<Satellite *> * SatConfigSys::getSatellitesFromMpcPl()
{
    QList<Satellite *> *satellites = new QList<Satellite *>;

    for(int current_row = 0; current_row < mpc_pl_proxyModel->rowCount(); current_row++)
    {
        QModelIndex name_index = mpc_pl_proxyModel->index(current_row, NAME_INDEX);
        QModelIndex note_index = mpc_pl_proxyModel->index(current_row, NOTE_INDEX);

        if(mpc_pl_proxyModel->data(name_index).toString() == "satName")
        {
            QModelIndex satellite_name_index = mpc_pl_proxyModel->index(current_row, VALUE_INDEX);
            satellites->append(new Satellite());
            satellites->last()->name_index = satellite_name_index;
        }
        else if(mpc_pl_proxyModel->data(note_index).toString() == "MissionConstraints")
        {
            QModelIndex mission_name_index = mpc_pl_proxyModel->index(current_row, NAME_INDEX);
            QModelIndex mission_value_index = mpc_pl_proxyModel->index(current_row, VALUE_INDEX);
            satellites->last()->mission_constraints_name.append(mission_name_index);
            satellites->last()->mission_constraints_value.append(mission_value_index);
        }
        else if(mpc_pl_proxyModel->data(note_index).toString() == "SystemConstraints")
        {
            QModelIndex system_name_index = mpc_pl_proxyModel->index(current_row, NAME_INDEX);
            QModelIndex system_value_index = mpc_pl_proxyModel->index(current_row, VALUE_INDEX);
            satellites->last()->system_constraints_name.append(system_name_index);
            satellites->last()->system_constraints_value.append(system_value_index);
        }
    }

    return satellites;
}

QString SatConfigSys::getCurrentParamValue(QSortFilterProxyModel* model, int row)
{
    QModelIndex old_value_index = model->index(row, VALUE_INDEX);
    QModelIndex new_value_index = model->index(row, VALUE_NEW_INDEX);
    if(model->data(new_value_index).toString().isEmpty())
    {
        return model->data(old_value_index).toString();
    }
    else
    {
        return model->data(new_value_index).toString();
    }
}
void SatConfigSys::onSaveToConfSatClicked(){
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(NULL, "windowTitle()", "Do you want to save new configuration files?",
                                  QMessageBox::Save|QMessageBox::Cancel);
    if (reply == QMessageBox::Save)
    {
        qDebug() << "Save was clicked";
        saveToConfSat();
    }
    else
    {
        qDebug() << "Cancel was clicked";
    }
}

void SatConfigSys::saveToConfSat(){
    /* Try and open a file for output */
    QFile outputFile(SAT_CONFIG_PATH);

    /* Check it opened OK */
    if(!outputFile.open(QIODevice::WriteOnly)){
        qDebug() << "Error, unable to open" << SAT_CONFIG_PATH << "for output";
    }

    /* Point a QTextStream object at the file */
    QTextStream outStream(&outputFile);

    for (int i = 0 ; i < data_model->rowCount() ; i++) {
        QString value;
        QString valueNew(data_model->item(i,VALUE_NEW_INDEX)->text());
        if(valueNew.isEmpty()){
            value = data_model->item(i,VALUE_INDEX)->text();
        } else {
            value = valueNew;
        }
        if(VALUE_LENGTH < value.length()){
            value.append(' ');
        }
        QString status = QString("%1%2%3%4%5%6")
                .arg(data_model->item(i,GROUPS_INDEX)->text(),-GROUP_LENGTH,' ')
                .arg(data_model->item(i,NAME_INDEX)->text(),-NAME_LENGTH,' ')
                .arg(data_model->item(i,TYPE_INDEX)->text(),-TYPE_LENGTH,' ')
                .arg(data_model->item(i,TYPE_UNIT_INDEX)->text(),-TYPE_UNIT_LENGTH,' ')
                .arg(value,-VALUE_LENGTH,' ')
                .arg(data_model->item(i,NOTE_INDEX)->text(),-NOTE_LENGTH,' ');
        qDebug() << status  << "\r\n";
        /* Write the line to the file */
//        outStream << status;
    }

    /* Close the file */
    outputFile.close();
}

void SatConfigSys::onTransferFilesClicked(){
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(NULL, "windowTitle()", "Do you want to save new configuration files?",
                                  QMessageBox::Save|QMessageBox::Cancel);
    if (reply == QMessageBox::Save)
    {
        qDebug() << "Save was clicked";
        saveGroupsToFile();
    }
    else
    {
        qDebug() << "Cancel was clicked";
    }
}

void SatConfigSys::transferFiles(){
    QString mpcPlFilepath = getFileNameWithDateTimeUtc("I_CNFM", ".xml");
    QString mpcAocsFilepath = getFileNameWithDateTimeUtc("I_CMOB", ".asc");
    QString fdsFilepath = getFileNameWithDateTimeUtc("I_CNFF", ".asc");
//    transferMpcPl(mpcPlFilepath);
    transferMpcAocs(mpcAocsFilepath);
    transferFds(fdsFilepath);
}

void SatConfigSys::transferMpcAocs(QString filepath){
    /* Try and open a file for output */
    QFile outputFile(filepath);

    /* Check it opened OK */
    if(!outputFile.open(QIODevice::WriteOnly)){
        qDebug() << "Error, unable to open" << filepath << "for output";
    }

    /* Point a QTextStream object at the file */
    QTextStream outStream(&outputFile);
    //File first line title
//    outStream << "$SATELLITE_CONF" << "\r\n";
    qDebug() << "$SATELLITE_CONF" << "\r\n";

    for (int i = 0 ; i < mpc_aocs_proxyModel->rowCount() ; i++) {
        QString value;
        QString valueNew(mpc_aocs_proxyModel->index(i,VALUE_NEW_INDEX).data().toString());
        if(valueNew.isEmpty()){
            value = mpc_aocs_proxyModel->index(i,VALUE_INDEX).data().toString();
        } else {
            value = valueNew;
        }
        if(mpc_aocs_proxyModel->index(i,TYPE_INDEX).data().toString() == "String"){
            value = QString("\"%1\"").arg(value);
        }
        QString status = QString("%1=%2")
                .arg(mpc_aocs_proxyModel->index(i,NAME_INDEX).data().toString())
                .arg(value);
        qDebug() << status << "\r\n";
        /* Write the line to the file */
//        outStream << status;
    }
//    outStream << "$END";
    qDebug() << "$END";
    outputFile.close();
}

void SatConfigSys::transferFds(QString filepath){
    /* Try and open a file for output */
    QFile outputFile(filepath);

    /* Check it opened OK */
    if(!outputFile.open(QIODevice::WriteOnly)){
        qDebug() << "Error, unable to open" << filepath << "for output";
    }

    /* Point a QTextStream object at the file */
    QTextStream outStream(&outputFile);
    //File first line title
//    outStream << "$SATELLITE_CONF" << "\r\n";
    qDebug() << "$SATELLITE_CONF" << "\r\n";

    for (int i = 0 ; i < fds_proxyModel->rowCount() ; i++) {
        QString value;
        QString valueNew(fds_proxyModel->index(i,VALUE_NEW_INDEX).data().toString());
        if(valueNew.isEmpty()){
            value = fds_proxyModel->index(i,VALUE_INDEX).data().toString();
        } else {
            value = valueNew;
        }
        if(fds_proxyModel->index(i,TYPE_INDEX).data().toString() == "String"){
            value = QString("\"%1\"").arg(value);
        }
        QString status = QString("%1=%2")
                .arg(fds_proxyModel->index(i,NAME_INDEX).data().toString())
                .arg(value);
        qDebug() << status << "\r\n";
        /* Write the line to the file */
//        outStream << status;
    }
//    outStream << "$END";
    qDebug() << "$END";
    outputFile.close();
}

QString SatConfigSys::getFileNameWithDateTimeUtc(QString initial_filename, QString file_extension)
{
    QDateTime dateTime = dateTime.currentDateTimeUtc();
    QString dateTimeString = dateTime.toString("yyyyMMdd_hhmmss");

    return initial_filename + "_" + dateTimeString + file_extension;
}

//void SatConfigSys::transferMpcPl(QString filepath)
//{
//    QFile mpc_pl_file(filepath);
//    if(!mpc_pl_file.open(QIODevice::WriteOnly))
//    {
//        qCritical() << "Error, unable to open MPC_PL file!!!";
//    }
//    QXmlStreamWriter mpc_pl_xml_writer(&mpc_pl_file);
//    QDateTime current_utc_date_time = current_utc_date_time.currentDateTimeUtc();
//    QString current_utc_date_time_str = current_utc_date_time.toString("yyyy-MM-ddThh:mm:ss");


//    mpc_pl_xml_writer.setAutoFormatting(true);
//    mpc_pl_xml_writer.setAutoFormattingIndent(-1); //Indent using one tab (spaces = positive, tabs = negative)

//    //XML Header
//    mpc_pl_xml_writer.setCodec("ISO-8859-1");
//    mpc_pl_xml_writer.writeStartDocument("1.0");

//    mpc_pl_xml_writer.writeCharacters("\r\n");

//    //SccMpcIf1 Header
//    mpc_pl_xml_writer.writeStartElement("SccMpcIf1");

//    //Construct SccMpcIf1 attributes
//    QXmlStreamAttributes SccMpcIf1;
//    SccMpcIf1.append("version", "1.0");
//    SccMpcIf1.append("xmlns:xsi", "http://www/w3.org/2001/XMLSchema-instance");
//    SccMpcIf1.append("xsi:noNameSpaceSchemaLocation", "SccMpcIf1.xsd");

//    mpc_pl_xml_writer.writeAttributes(SccMpcIf1);

//    //Header definition
//    mpc_pl_xml_writer.writeStartElement("headerDefinition");
//    mpc_pl_xml_writer.writeStartElement("timestamp");
//    mpc_pl_xml_writer.writeTextElement("dateAndTime", current_utc_date_time_str);
//    mpc_pl_xml_writer.writeEndElement();
//    mpc_pl_xml_writer.writeTextElement("source", "ASTRIUM-AEA52");
//    mpc_pl_xml_writer.writeEndElement();

//    mpc_pl_xml_writer.writeStartElement("dataBlock");
//    mpc_pl_xml_writer.writeAttribute("version", "1.0");


//    //Start actual content
//    int starting_row = 1; //First row of actual data in model_MPC_PL, row 0 is XML version number
//    QString current_satName_note = "";
//    QString mode = "staName";

//    for(int current_row = starting_row; current_row < model_MPC_PL->rowCount(); current_row++)
//    {

//        if(model_MPC_PL->item(current_row, param_name_index)->text() == "staName")
//        {
//            mode = "staName";
//            mpc_pl_xml_writer.writeStartElement(getCurrentParamValue(model_MPC_PL, current_row));
//            mpc_pl_xml_writer.writeStartElement("Definition");
//        }

//        else if(model_MPC_PL->item(current_row, param_name_index)->text() == "satName")
//        {
//            mode = "satName";
//            mpc_pl_xml_writer.writeStartElement(getCurrentParamValue(model_MPC_PL, current_row));

//            if(current_row+1 < model_MPC_PL->rowCount())
//            {
//                current_satName_note = model_MPC_PL->item(current_row+1, note_index)->text();
//                mpc_pl_xml_writer.writeStartElement(current_satName_note);
//            }
//        }

//        else
//        {
//            mpc_pl_xml_writer.writeTextElement(model_MPC_PL->item(current_row, param_name_index)->text()
//                                               ,getCurrentParamValue(model_MPC_PL, current_row));

//            if(current_row+1 < model_MPC_PL->rowCount())
//            {
//                if(mode == "staName" && model_MPC_PL->item(current_row+1, note_index)->text() == "nocase")
//                {
//                    //Find new staName, end this element loop
//                    mpc_pl_xml_writer.writeEndElement(); //End "Definition" element
//                    mpc_pl_xml_writer.writeEndElement(); //End <staName> element
//                }
//                else if(mode == "satName" && current_satName_note != model_MPC_PL->item(current_row+1, note_index)->text())
//                {
//                    mpc_pl_xml_writer.writeEndElement();
//                    current_satName_note = model_MPC_PL->item(current_row+1, note_index)->text();
//                    mpc_pl_xml_writer.writeStartElement(current_satName_note);
//                }
//            }
//        }
//    }

//    mpc_pl_xml_writer.writeEndDocument(); //End the rest of unended elements (i.e. /Theos1, /dataBlock, /SccMpcIf1)
//}

