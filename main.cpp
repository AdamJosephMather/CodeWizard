#include "mainwindow.h"
#include <QFontDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	int fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/Courier_New.ttf");
	if (fontId == -1) {
		qWarning("Failed to load cn!");
	}
	fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/Courier_Prime.ttf");
	if (fontId == -1) {
		qWarning("Failed to load cp!");
	}
	fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/DroidSansMono.ttf");
	if (fontId == -1) {
	   qWarning("Failed to load dsm!");
	}
	fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/SourceCodePro-Regular.ttf");
	if (fontId == -1) {
		qWarning("Failed to load scp!");
	}
	fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/UbuntuMono-R.ttf");
	if (fontId == -1) {
		qWarning("Failed to load umr!");
	}
	fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/Monospace.ttf");
	if (fontId == -1) {
		qWarning("Failed to load ms!");
	}
	fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/Monaco.ttf");
	if (fontId == -1) {
		qWarning("Failed to load mc!");
	}

	if (fontId == -1) {
		// Handle font loading error
		qWarning("Failed to load font!");
	}

	QString fileName;
	if (argc > 1) {
		fileName = argv[1];
	}

	a.setWindowIcon(QIcon(":/resources/Python.ico"));
	MainWindow w(fileName);
	w.show();
	return a.exec();
}
