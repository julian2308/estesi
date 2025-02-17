# Contextualización del reto:    

Los cerros orientales de Bogotá son una zona de gran importancia ecológica y ambiental. Sin embargo, debido a factores como la sequía y la actividad humana, estos cerros son susceptibles a incendios forestales. La detección temprana de incendios es fundamental para minimizar daños y proteger tanto el medio ambiente como las comunidades cercanas. En los últimos años, los incendios forestales en los cerros orientales han sido una preocupación creciente. Las temperaturas medias anuales en esta zona varían desde los 8.4°C a los 13°C. Un aumento repentino y significativo en la temperatura, por ejemplo, un incremento de 5°C en un corto período de tiempo puede indicar la presencia de un incendio. Además, la detección de partículas de humo o llama y la presencia de gases como el monóxido de carbono (CO) y el dióxido de carbono (CO₂) son indicadores clave de combustión. En recientes incendios, se han observado columnas de humo y llamas visibles desde varios sectores de la ciudad, y se han generado emisiones significativas de estos gases. 

A partir de lo anterior, se propone desarrollar un prototipo funcional de un sistema IoT para monitorizar y detectar en tiempo real la presencia de incendios en los cerros orientales de Bogotá. El sistema debe ser capaz de notificar in situ a las autoridades locales en caso de detectar un incendio.

# Diseño

Se propone utilizar un Sistema Embebido como la ESP32 utilizando sensores de temperatura, humo, llama y gases como el Monóxido de Carbono o el Dióxido de Carbono para realizar la apropiada identificación en casos de incendio.Por otro lado, para emitir la alarma de incendio se utilizaran de actuadores un LED RGB que indican el nivel de peligro según el aumento de temperatura o la presencia de gases combustibles, una pantalla LCD la cual mostrara el nivel de emergencia y además una buzzer pasivo que emitira una alarma en caso de incendio. A continuación se mostrara el diseño planteado:

# Autoevaluación del protocolo de pruebas
Dentro del protocolo de pruebas se midieron 2 variables, los gases inflamables presentes en el entorno con ayuda del sensor MQ2, el cual es capaz de detectar concentración de sustancias como el butano y el propano. Además, también se midió la temperatura, en este caso en grados centígrados. 
Dentro de las pruebas realizadas se tomó en cuenta distintos escenarios, como el aumento repentino de la temperatura leída por el sensor, y el incremento de gases que sobrepasaran la barrera definida. El aumento de temperatura se probó tanto con el encendido de un mechero como soplándole directamente al sensor, lo cual presentó algunos problemas debido a que en ocasiones reconocía bien el aumento de la temperatura y en otras no. Mientras, para la prueba del MQ2 funcionó perfectamente al detectar el aumento de los gases que se generaron con ayuda del encendedor, accionando correctamente los actuadores establecidos.

# Configuración experimental, resultados y análisis.

![image](https://github.com/user-attachments/assets/e8ba4dae-970f-4587-ba13-0aa24b34fe82)
Figura 1: Foto del montaje

![image](https://github.com/user-attachments/assets/40657e7e-5e57-4167-808d-fa871ef870e3)
Figura 2: Foto del montaje

Para llevar a cabo la correcta identificación de incendios se hizo uso de:

- Pantalla LCD 16A02
- LED-RGB
- Buzzer Passivo
- ESP32
- Sensorde gases combustibles y humo(MQ-2)
- Sensor de termperatura (ds18b20)

El color del LED indica el nivel de peligro en la zona, variando entre verde ( no presencia de gases y sin aumentos de temperatura drásticos ), amarillo (no presencia de gases pero aumento de temperatura) y rojo (Presencia de gases combustibles en la zona). Por otro lado, la pantalla LCD se encarga de mostrar la temperatura que se registra cada segundo y el nivel de alerta asociado a los colores del LED-RGB con amarillo- Aumento de temp. y rojo - ¡PELIGRO!. Además, el sistema al entrar en estado de peligro activa el buzzer emitiendo una señal de alarma.

Con la realización del laboratorio se evidencia cómo los dispositivos IoT pueden proporcionarnos una ayuda para evitar problemas que requieren de acción inmediata, como por ejemplo, la aparición de incendios forestales en los cerros orientales de Bogotá. No solo nos permiten una identificación y medición de variables de interés temprana sino también mecanismos de acción para mitigar el impacto de dichos eventos. 
