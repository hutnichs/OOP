#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include "module1.h"
#include "module2.h"


int main(int argc, char *argv[])
{
    QApplication Dodatok(argc, argv);

    QMainWindow vikno;
    vikno.setWindowTitle("Лаба 1");
    vikno.resize(400, 300);

    auto *centralLabel = new QLabel("", &vikno);
    centralLabel->setAlignment(Qt::AlignCenter);
    vikno.setCentralWidget(centralLabel);

    QMenuBar *MoyoMenuBar = vikno.menuBar();
    QMenu *MoyoMenu = MoyoMenuBar->addMenu("Моє меню");

    QAction *Robota1 = new QAction("робота1",&vikno);
    QAction *Robota2 = new QAction("робота2",&vikno);

    MoyoMenu->addAction(Robota1);
    MoyoMenu->addAction(Robota2);

    module1 mod1;

    QObject::connect(Robota1, &QAction::triggered, [&mod1]() {
        mod1.open();
    });

    module2 mod2;

    QObject::connect(Robota2, &QAction::triggered, [&mod2, centralLabel]() {
        mod2.open([centralLabel](const QString &receivedText) {
            centralLabel->setText(receivedText);
        });
    });

    vikno.show();

    return Dodatok.exec();
}
