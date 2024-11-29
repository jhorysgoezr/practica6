#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "SistemaGravitacional.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void actualizarSimulacion();  // Método para actualizar la simulación

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;       // Escena para la visualización
    SistemaGravitacional sistema; // Sistema gravitacional
    QTimer *temporizador;         // Temporizador para la animación
};

#endif // MAINWINDOW_H
