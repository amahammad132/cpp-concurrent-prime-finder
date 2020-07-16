#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QWidget>
#include <string>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QTextEdit>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QtCore/QTextStream>

class TextInput : public QWidget {
public:
    int threads;
    int start;
    int end;

    TextInput() {
        auto title = tr("C++ Fast Prime");
        bool ok;
        threads = QInputDialog::getInt(this, title, tr("Number of threads:"),
                                       4, 1, 48, 1, &ok);

        start = QInputDialog::getInt(this, title,tr("Starting value:"),
                                     1, 0, 100000, 100, &ok);

        end = QInputDialog::getInt(this, title,tr("Ending Value:"),
                                   start + 1000, start + 1, 100000000, 100, &ok);
    }
};

class PrimeOutputBox : QTextEdit {
public:
    QTextEdit outputPrimes;

    PrimeOutputBox() {
        outputPrimes.setFontPointSize(18);
        outputPrimes.setReadOnly(true);
        outputPrimes.resize(500, 500);
    };

    void addItem(int item) {
        outputPrimes.append(QString::fromStdString(std::to_string(item) + ","));
    }
};

class MyWidget : public QWidget {
public:
    TextInput inputBox;
    PrimeOutputBox outputBox;

    MyWidget() = default;
};
