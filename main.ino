#include <Wire.h>
   #include <Adafruit_MLX90614.h>

   Adafruit_MLX90614 mlx = Adafruit_MLX90614();

   void setup() {
     Serial.begin(9600);

     if (!mlx.begin()) {
       Serial.println("Ошибка подключения к MLX90614. Проверьте соединение.");
       while (1);
     }

     Serial.println("MLX90614 подключен успешно!");
   }

   void loop() {
     // Чтение температуры объекта (в градусах Цельсия)
     float objectTemp = mlx.readObjectTempC();
     // Чтение температуры окружающей среды (в градусах Цельсия)
     float ambientTemp = mlx.readAmbientTempC();

     Serial.print("Температура объекта: ");
     Serial.print(objectTemp);
     Serial.println(" °C");

     Serial.print("Температура окружающей среды: ");
     Serial.print(ambientTemp);
     Serial.println(" °C");

     delay(1000); // Задержка 1 секунда
   }
