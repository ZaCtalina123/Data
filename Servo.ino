
#include <Servo.h>

Servo servoX; // Серво для оси X
Servo servoY; // Серво для оси Y

const int numRows = 5; // Количество строк
const int numCols = 5; // Количество столбцов
const int stepSize = 36; // Шаг в градусах между точками (180° / 5 = 36°)

void setup() {
 servoX.attach(9); // Подключаем первый сервопривод к пину 9 (ось X)
 servoY.attach(10); // Подключаем второй сервопривод к пину 10 (ось Y)

 // Начальные позиции
 servoX.write(0);
 servoY.write(0);
 delay(1000); // Ждем 1 секунду, чтобы сервоприводы успели переместиться
}

void drawMatrix() {
 for (int row = 0; row < numRows; row++) ws; row++) {
 for (int col = 0; col < numCols; col++) {
 // Перемещаем серво по X и Y
 int xPosition = col * stepSize; // Угол для оси X
 int yPosition = row * stepSize; // Угол для оси Y

 servoX.write(xPosition); // Двигаем по оси X
 servoY.write(yPosition); // Двигаем по оси Y
 delay(500); // Ждем, пока сервоприводы достигнут угла

 // Здесь можно добавить код для "подсветки" точки, если это необходимо
 }
 }
}

void loop() {
 drawMatrix(); // Рисуем матрицу
 while (true); // Останавливаем выполнение программы после рисования
}
