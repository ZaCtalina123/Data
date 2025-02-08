
#include <Servo.h>

Servo servoX; // Серво для оси X
Servo servoY; // Серво для оси Y

void setup() {
 servoX.attach(9); // Подключаем первый сервопривод к пину 9 (ось X)
 servoY.attach(10); // Подключаем второй сервопривод к пину 10 (ось Y)

 // Начальные позиции
 servoX.write(0);
 servoY.write(0);
 delay(1000); // Ждем 1 секунду, чтобы сервоприводы успели переместиться
}

void drawX() {
 // X() {
 // Рисуем X
 for (int pos = 0; pos <= 180; pos += 10) {
 servoX.write(pos); // Двигаем по оси X
 servoY.write(pos); // Двигаем по оси Y в соответствии с текущей позицией X
 delay(500); // Ждем, пока сервоприводы достигнут угла
 }
 for (int pos = 180; pos >= 0; pos -= 10) {
 servoX.write(pos); // Двигаем по оси X
 servoY.write(180 • pos); // Двигаем по оси Y в обратном направлении
 delay(500); // Ждем, пока сервоприводы достигнут угла
 }
}

void loop() {
 drawX(); // Рисуем X
 while (true); // Останавливаем выполнение программы после рисования
}
