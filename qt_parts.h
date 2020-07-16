#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QInputDialog>
#include <QtCore/QTextStream>

class MyWidget : public QWidget {
public:
    int threads;
    int start;
    int end;

    MyWidget() {
        bool ok;
        auto title = tr("C++ Fast Prime");
        threads = QInputDialog::getInt(this, title,
                                     tr("Number of threads:"), 4, 1, 48, 1, &ok);

        start = QInputDialog::getInt(this, title,
                                     tr("Starting value:"), 1, 0, 100000, 100, &ok);

        end = QInputDialog::getInt(this, title,
                                         tr("Ending Value:"), start + 1000, start + 1, 100000000, 100, &ok);
    }
};
