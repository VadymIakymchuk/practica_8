# Práctica 8: Buses de comunicación IV (uart)

## Ejercicio Práctico 1

```cpp
#include <Arduino.h>

uint8_t incomingByte=0;

void setup()
{
    Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1,16,17);  
    Serial2.print(incomingByte);
}

void loop() 
{
  // send data only when you receive data:
    while (Serial2.available() > 0) 
    {
        Serial.print(incomingByte);
    
        // read the incoming byte:
        incomingByte = Serial2.read();
    
        Serial.println(incomingByte);
        incomingByte++;
    
        Serial.println(incomingByte);
        Serial2.write(incomingByte);
        // say what you got:
    }
  
    Serial.print("I received: ");
    Serial.println(incomingByte);
    delay(1000);
}
```

Explicacion: En el setup(), se inicia el puerto serial. Luego, se inicia otra instancia de comunicación serial llamada "Serial2" con la misma velocidad de 115200 baudios y se configuran los pines de comunicación para esta instancia utilizando "Serial2.begin(115200, SERIAL_8N1, 16, 17)". En este caso, se utilizan los pines 16 y 17 del ESP32 para la comunicación serial. Se envía el valor de la variable "incomingByte" a través de la comunicación serial utilizando "Serial2.print(incomingByte)". Dado que inicialmente no se ha asignado ningún valor a "incomingByte", se enviará el valor cero. En el loop() cada vez que la placa de "autoenvie" la señal serial, el valor del byte recibido ira aumentando y se ira proyectando en el terinal Serie con un "I recieved: (valor de incomingByte)".
