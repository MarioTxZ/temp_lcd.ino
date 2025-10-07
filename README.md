# temp_lcd.ino
*Este proyecto implementa un sistema de monitoreo y control de temperatura utilizando un sensor de temperatura TMP36, un display LCD 16x2, un LED rojo como indicador de alerta, y un motor DC que simula un ventilador.
El sistema mide la temperatura ambiente, la muestra en pantalla y activa el ventilador automáticamente cuando se supera un umbral establecido (por defecto 26 °C).

*El circuito fue diseñado y probado en Tinkercad Circuits, pero también puede montarse físicamente con componentes reales.

*Componentes Utilizados

Nombre / Cantidad / Componente

U1 /	1 /	Arduino Uno R3

Rpot1 /	1 /	Potenciómetro de 220 Ω

R1 /	1 /	Resistencia de 1 kΩ

D1 /	1 /	LED Rojo

R2 /	1	/ Resistencia de 220 Ω

M1 /	1 /	Motor de CC

D2 /	1 /	Diodo (1N4007 o similar)

ULcd_1 /	1 /	Pantalla LCD 16x2

U3 /	1 /	Sensor de temperatura TMP36

*Conexiones del Circuito

**Sensor TMP36

Pin	    /    Conexión

VCC	    /    5V

VOUT	  /    A0

GND	    /    GND


*Pantalla LCD 16x2 (modo 4 bits)

Pin LCD	  /  Conexión Arduino

RS	  /      12

E	    /      11

D4	   /     5

D5     /   	4

D6	    /    3

D7	   /     2

VSS	    /    GND

VDD	    /    5V

VO	     /   Potenciómetro (ajuste de contraste)

RW	    /    GND

LED de alerta

Elemento	              /          Conexión

Ánodo (lado largo)	     /         Pin 8

Cátodo	Resistencia de 220 Ω →  /  GND


*Motor DC + Diodo

Elemento	/ Conexión

Motor (+)	 / 5V

Motor (–) / Pin 10 (control)

Diodo	En paralelo con el motor (ánodo al pin 10, cátodo al +5V)

*El sistema lee la temperatura desde el sensor TMP36, la convierte a grados Celsius y la muestra en el LCD.
Cuando la temperatura excede los 26 °C, el motor DC se activa simulando la ventilación, y se enciende el LED rojo como señal de advertencia.

Temperatura (°C) /	Estado /	Acción

≤ 25 °C	/ Normal /	Motor apagado, LED apagado

≥ 26 °C	/ Alta /	Motor encendido, LED encendido
