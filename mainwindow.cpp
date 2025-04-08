#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singleWordTranslator.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// Helper function: returns true if the text contains any Cyrillic characters.
bool isRussianText(const QString &text) {
    for (QChar ch : text) {
        ushort uni = ch.unicode();
        if (uni >= 0x0400 && uni <= 0x04FF)
            return true;
    }
    return false;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up your PostgreSQL database connection.
    // Make sure the QPSQL driver is available and that your connection info is correct.
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("translationdb"); // change to your database name
    db.setUserName("your_username");       // change to your username
    db.setPassword("your_password");       // change to your password
    if (!db.open()) {
        qDebug() << "Database connection error:" << db.lastError().text();
    }

    // Connect the Translate button to the translation slot.
    connect(ui->btnTranslate, &QPushButton::clicked, this, &MainWindow::onTranslateClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTranslateClicked()
{
    // Retrieve the user's input word.
    QString input = ui->txtInput->text().trimmed();
    if (input.isEmpty()) {
        ui->txtResult->setText("Please enter a word");
        return;
    }

    // Automatically detect the language.
    bool inputIsRussian = isRussianText(input);
    QString queryStr;

    if (inputIsRussian) {
        // Translate from Russian to English.
        queryStr = "SELECT english_word FROM english_words "
                   "INNER JOIN russian_words ON english_words.id = russian_words.id "
                   "WHERE russian_words.russian_word % :input "
                   "ORDER BY similarity(russian_words.russian_word, :input) DESC LIMIT 1";
    } else {
        // Translate from English to Russian.
        queryStr = "SELECT russian_word FROM english_words "
                   "INNER JOIN russian_words ON english_words.id = russian_words.id "
                   "WHERE english_words.english_word % :input "
                   "ORDER BY similarity(english_words.english_word, :input) DESC LIMIT 1";
    }

    // Create an instance of the translator with the appropriate query.
    singleWordTranslator translator(queryStr);
    QString translation = translator.translate(input);

    // Display the translation, or an error message if not found.
    if (translation.isEmpty())
        ui->txtResult->setText("Translation not found");
    else
        ui->txtResult->setText(translation);
}
