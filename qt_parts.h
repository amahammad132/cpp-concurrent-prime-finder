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
    QString items_to_show = "";

    PrimeOutputBox() = default;

    void addItem(int item) {
        items_to_show.append(QString::fromStdString(std::to_string(item) + "\n"));
    }

    void setToFullOutput() const {
        auto outputPrimes = new QTextEdit();
        outputPrimes->setFontPointSize(18);
        outputPrimes->setText(items_to_show);
        outputPrimes->setReadOnly(true);
        outputPrimes->show();
    }
};

class MyWidget : public QWidget {
public:
    TextInput input;
    PrimeOutputBox primeOutputBox;

    MyWidget() = default;
};
