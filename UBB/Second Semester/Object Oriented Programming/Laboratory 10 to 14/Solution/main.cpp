#include "GUI.h"
#include "Tests.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    run_all_tests();
    QApplication a(argc, argv);
    FileRepository repo("medicine.txt");
    Validator valid;
    Service srv(repo, valid);
    MedicineGUI w(srv);
    //PrescriptionCRUDGUI crud_gui(srv);
    //PrescriptionReadOnlyGUI paint_gui(srv);
    w.show();
    //crud_gui.show();
    //paint_gui.show();
    return a.exec();
}
