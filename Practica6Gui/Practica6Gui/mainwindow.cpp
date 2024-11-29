#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QPen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Configurar la escena
    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);

    // Configurar el sistema gravitacional
    sistema.agregarCuerpo(Cuerpo(0, -7000, 70, 10, 2, 0));
    sistema.agregarCuerpo(Cuerpo(0, 0, 70000, 15, 0, 0));
    sistema.agregarCuerpo(Cuerpo(4000, 5000, 25, 8, -1.6, 1.2));

    // Configurar el temporizador
    temporizador = new QTimer(this);
    connect(temporizador, &QTimer::timeout, this, &MainWindow::actualizarSimulacion);
    temporizador->start(50); // Actualización cada 50 ms
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::actualizarSimulacion() {
    // Limpiar la escena
    escena->clear();

    // Simular un paso
    sistema.simular();

    // Dibujar los cuerpos
    for (const auto &cuerpo : sistema.cuerpos) {
        QGraphicsEllipseItem *circulo = escena->addEllipse(cuerpo.x - cuerpo.radio,
                                                           cuerpo.y - cuerpo.radio,
                                                           cuerpo.radio * 2,
                                                           cuerpo.radio * 2,
                                                           QPen(Qt::NoPen),
                                                           QBrush(Qt::blue));
        escena->addLine(cuerpo.x, cuerpo.y, cuerpo.x - cuerpo.vx, cuerpo.y - cuerpo.vy, QPen(Qt::gray));
    }
}
