
# Introducción

### Resumen General


### Motivación
Los cerros orientales de Bogotá son una zona de gran importancia ecológica y ambiental. Sin embargo, debido a factores como la sequía y la actividad humana, estos cerros son susceptibles a incendios forestales. La detección temprana de incendios es fundamental para minimizar daños y proteger tanto el medio ambiente como las comunidades cercanas. En los últimos años, los incendios forestales en los cerros orientales han sido una preocupación creciente. Las temperaturas medias anuales en esta zona varían desde los 8.4°C a los 13°C. Un aumento repentino y significativo en la temperatura, por ejemplo, un incremento de 5°C en un corto período de tiempo puede indicar la presencia de un incendio. Además, la detección de partículas de humo o llama y la presencia de gases como el monóxido de carbono (CO) y el dióxido de carbono (CO₂) son indicadores clave de combustión. En recientes incendios, se han observado columnas de humo y llamas visibles desde varios sectores de la ciudad, y se han generado emisiones significativas de estos gases.

### Introducción
Para abordar la problemática de los incendios forestales en los cerros orientales de Bogotá, se desarrolló un prototipo funcional de un sistema IoT para monitorizar y detectar en tiempo real la presencia de incendios. El sistema está diseñado para notificar con alarma, luz y mensajes en pantalla a las autoridades presentes. La solución incluye el uso de un microcontrolador ESP32, sensores de temperatura (DS18B20), de gases (MQ-2) y de llama (LM393), así como actuadores como un buzzer y un LED RGB para alarmas visuales y sonoras. Además, se utiliza una pantalla LCD para la visualización de datos en tiempo real.

El desarrollo del sistema se llevó a cabo utilizando la plataforma de simulación Wokwi, que permitió probar y validar el funcionamiento del prototipo antes de su implementación física. El código desarrollado incluye la lectura de los sensores, el procesamiento de los datos y el control de los actuadores. Se establecieron umbrales específicos para la detección de gases, incrementos de temperatura. La simulación en Wokwi permitió ajustar estos umbrales y asegurar que el sistema respondiera adecuadamente a las condiciones de alarma. Pero no simula totalmente el prototípo, ya que el simulador tiene un limite en su capacidad, entonces se decidio no implementar el sensor de llama (LM393).

El montaje del prototipo se realizó conectando los componentes al microcontrolador ESP32 según el esquemático de hardware diseñado. Los sensores MQ-2, DS18B20 y LM393 se conectaron a los pines correspondientes del ESP32, al igual que el buzzer y el LED RGB. La pantalla LCD se conectó mediante la interfaz I2C. Una vez montado, el sistema fue probado en condiciones controladas para verificar su funcionamiento, pero en la practica la implementación del sensor LM393 fue fallida. El ESP32 lee continuamente los valores de los sensores, procesa los datos y controla los actuadores para emitir alarmas visuales y sonoras en caso de detección de incendios. La pantalla LCD muestra la temperatura en tiempo real y cualquier mensaje de alerta relevante.

### Justificación
La implementación de un sistema IoT para la detección temprana de incendios en los cerros orientales de Bogotá es crucial debido a la vulnerabilidad de esta área a los incendios forestales. La capacidad de detectar y notificar la presencia de incendios de manera oportuna puede reducir significativamente los daños ambientales y económicos, así como proteger la vida humana y la fauna local. Además, este proyecto puede servir como modelo para otras regiones con problemas similares, promoviendo el uso de tecnologías avanzadas en la gestión de desastres naturales.

### Estructura de la Documentación
La documentación de este proyecto se estructura de la siguiente manera:

1. **Introducción**: Resumen general, motivación, justificación y estructura de la documentación.
2. **Solución Propuesta**: Descripción detallada de las restricciones de diseño identificadas, la arquitectura propuesta, el desarrollo teórico modular, los diagramas UML de la solución y de cada módulo software desarrollado, el esquemático de hardware diseñado y los estándares de diseño de ingeniería aplicados.
3. **Configuración Experimental, Resultados y Análisis**: Descripción de la configuración experimental, presentación de los resultados obtenidos y análisis de los mismos.
4. **Autoevaluación del Protocolo de Pruebas**: Evaluación del protocolo de pruebas utilizado para validar el funcionamiento del sistema.
5. **Conclusiones, Retos y Trabajo Futuro**: Conclusiones del proyecto, retos presentados durante el desarrollo y posibles mejoras y trabajos futuros.
6. **Anexos**: Código fuente completamente documentado, esquemáticos y material complementario.
7. **Video Demostrativo**: Enlace a un video demostrativo y explicativo de la etapa de validación del prototipo funcional.


# Solución Propuesta

## Restricciones de Diseño

### Restricciones Técnicas
La selección de componentes se basa en la disponibilidad local (entregados y disponibles en el kit) y la compatibilidad con el microcontrolador ESP32. Se utilizarán sensores de temperatura (DS18B20) y de gases (MQ-2), así como actuadores como el buzzer y el LED RGB. Dado que en los cerros orientales puede haber áreas con acceso limitado a la red eléctrica y de comunicaciones, el sistema debe ser eficiente en el consumo de energía y capaz de operar de manera autónoma con baterías o paneles solares. Sin embargo, el prototipo estará restringido a funcionar conectado al voltaje de una laptop. Además, sin una red de comunicaciones, la notificación efectiva a las autoridades es una restricción que evita una solución óptima para la necesidad. A nivel del prototípado, el simulador Wokwi (Simulador para la ESP-32), tenia varias restricciones en cuanto a carga y sensores (MQ-2 y LM393)

### Restricciones Económicas
El proyecto debe ajustarse a un presupuesto limitado, priorizando componentes de bajo costo y alta disponibilidad. Esto es crucial debido a la cantidad de dispositivos inteligentes que habría que implementar a lo largo de los cerros y la limitación de ser un proyecto universitario.

### Restricciones Regulatorias
Los cerros orientales de Bogotá están protegidos bajo la Resolución 076 de 1977 del Ministerio de Agricultura y la Resolución 1141 de 2006 de la Corporación Autónoma Regional de Cundinamarca (CAR). Estas normativas establecen restricciones sobre el uso del suelo y la conservación de la flora y fauna, lo que implica que cualquier instalación debe minimizar el impacto ambiental. Además, la Resolución 463 de 2005 del Ministerio de Ambiente, Vivienda y Desarrollo Territorial establece la zonificación y reglamentación de usos en los cerros orientales, incluyendo áreas de recuperación ambiental y zonas de ocupación pública prioritaria, donde se deben seguir estrictas directrices para la instalación de cualquier infraestructura.

### Restricciones de Espacio
Los dispositivos deben ser instalados en ubicaciones estratégicas que maximicen la cobertura de monitoreo sin interferir con el ecosistema local. Esto implica un diseño compacto y discreto para minimizar el impacto visual y físico. Las ubicaciones seleccionadas deben ser accesibles para el mantenimiento y la supervisión periódica, considerando la topografía y las condiciones del terreno. Además, estos dispositivos tendrán que soportar las condiciones ambientales y climáticas del terreno.

### Restricciones de Escalabilidad
El diseño debe permitir la adición de más sensores y actuadores en el futuro sin requerir una reestructuración completa del sistema. Esto asegura que el sistema pueda expandirse para cubrir áreas adicionales o incorporar nuevas tecnologías. Además, el sistema debe ser compatible con otros dispositivos y plataformas de monitoreo ambiental, facilitando la integración con sistemas existentes y futuros. Debido a las restricciones técnicas mencionadas anteriormente, este proyecto tiene una restricción de estabilidad que impide mejorar a una solución óptima.

### Restricciones Temporales
El proyecto debe estar completamente implementado y funcional para la fecha de presentación (18/02/25). Esto requiere una planificación detallada y una ejecución eficiente de todas las etapas del proyecto. Se debe reservar tiempo suficiente para realizar pruebas exhaustivas y validar el funcionamiento del sistema en condiciones reales, asegurando que cumple con los requisitos y restricciones establecidos.

Con estas restricciones claramente definidas, podemos proceder a detallar la arquitectura propuesta, los diagramas y los estándares de diseño aplicados.

# Diseño

Se propone utilizar un Sistema Embebido como la ESP32 utilizando sensores de temperatura, humo, llama y gases como el Monóxido de Carbono o el Dióxido de Carbono para realizar la apropiada identificación en casos de incendio.Por otro lado, para emitir la alarma de incendio se utilizaran de actuadores un LED RGB que indican el nivel de peligro según el aumento de temperatura o la presencia de gases combustibles, una pantalla LCD la cual mostrara el nivel de emergencia y además una buzzer pasivo que emitira una alarma en caso de incendio. A continuación se mostrara el diseño planteado:  

## Arquitectura 
### Hardware
<img width="468" alt="image" src="https://github.com/user-attachments/assets/36086f94-e6a8-4206-ba02-f1a6913d0d03" />

Figura 1. Diseño de Arquitectura de Hardware del Detector de Incendios.

### Software
<img width="468" alt="image" src="https://github.com/user-attachments/assets/c1756fbc-5960-4e40-880d-2a693fc56872" />

Figura 2. Diseño de Arquitectura de Software del Detector de Incendios.

## Desarrollo Teórico Modular

### Criterios de Diseño Establecidos

**Detección de Gases**:
Para la detección de gases, se ha seleccionado el sensor MQ-2 debido a su capacidad para identificar una variedad de gases, incluyendo el monóxido de carbono (CO) y el dióxido de carbono (CO₂), que son indicadores clave de combustión. Este sensor es económico y ampliamente disponible, lo que lo hace ideal para el proyecto. Se ha establecido un umbral de detección basado en pruebas preliminares y datos de referencia. Un valor de lectura superior a 600 indica la presencia de gases en niveles que podrían sugerir un incendio.

**Detección de Temperatura**:
La medición de la temperatura ambiente se realiza mediante el sensor DS18B20, seleccionado por su precisión y facilidad de uso. Este sensor proporciona lecturas de temperatura con una precisión de ±0.5°C. Se ha definido un umbral de incremento de temperatura de 5°C en un corto período de tiempo como indicador de un posible incendio. Este umbral se basa en la variabilidad normal de la temperatura en los cerros orientales y en la necesidad de detectar incrementos significativos que puedan sugerir la presencia de fuego.

**Detección de Llamas**:
Para la detección de llamas, se ha incorporado el sensor de llama LM393. Este sensor es capaz de detectar la presencia de llamas mediante la captura de la radiación infrarroja emitida por el fuego. Se ha configurado el sensor para que detecte llamas cuando la salida digital es baja (valor 0), lo que indica la presencia de fuego.

**Alarmas Visuales y Sonoras**:
Para las alarmas visuales y sonoras, se ha optado por utilizar un buzzer y un LED RGB. El buzzer emite una alarma sonora en caso de detección de incendio, siendo controlado por el ESP32 y activado cuando se detecta un incremento significativo en la temperatura, la presencia de gases o llamas. El LED RGB proporciona una señal visual de alerta, cambiando de color según las condiciones detectadas: rojo para la presencia de gases o llamas, amarillo para un incremento de temperatura y verde para condiciones normales.

**Visualización de Datos**:
La visualización de los datos se realiza mediante una pantalla LCD, que muestra la temperatura en tiempo real y mensajes de alerta. La pantalla LCD es controlada por el ESP32 y se actualiza continuamente con los datos de los sensores, proporcionando información clara y precisa sobre las condiciones ambientales.

## Diagrama de UML

<img width="468" alt="image" src="https://github.com/user-attachments/assets/80147838-9a35-49ea-8f04-e1e7dff175f0" />

Figura 3. Diagrama de UML de la Solución y de Cada Módulo Software Desarrollado del Detector de Incendios.

## Diagrma de Actividad UML
<img width="468" alt="image" src="https://github.com/user-attachments/assets/3401ac5c-741a-4d87-81ac-e4b82f0895c1" />

Figura 4. Diagrama de Actividad UML para los Procesos del Detector de Incendios.

## Simulación en Wokwi

La carpeta `/IoT Challenge (1)` contiene los archivos necesarios para la simulación del proyecto en Wokwi. A continuación, se describe brevemente el contenido de cada archivo y subcarpeta:

- Configuración del circuito en Wokwi (diagram.json)
- Código principal de Arduino/ESP32 (sketch.ino)
- **custom-chips/**: Carpeta que contiene definiciones y lógica personalizada para chips específicos utilizados en el proyecto.
  - **mq-2.chip/**: Subcarpeta que contiene los archivos relacionados con el sensor MQ-2.
    - Definición del MQ-2 (pines y controles) (mq-2.chip.json)
    - Lógica del chip en C (mq-2.chip.c)

## Esquematico y Conexiones de Hardware en Wokwi
<img width="468" alt="image" src="https://github.com/user-attachments/assets/61ca2c58-59bb-4155-bd72-15384eb7f414" />



# Autoevaluación del protocolo de pruebas
Dentro del protocolo de pruebas se midieron 2 variables, los gases inflamables presentes en el entorno con ayuda del sensor MQ2, el cual es capaz de detectar concentración de sustancias como el butano y el propano. Además, también se midió la temperatura, en este caso en grados centígrados. 
Dentro de las pruebas realizadas se tomó en cuenta distintos escenarios, como el aumento repentino de la temperatura leída por el sensor, y el incremento de gases que sobrepasaran la barrera definida. El aumento de temperatura se probó tanto con el encendido de un mechero como soplándole directamente al sensor, lo cual presentó algunos problemas debido a que en ocasiones reconocía bien el aumento de la temperatura y en otras no. Mientras, para la prueba del MQ2 funcionó perfectamente al detectar el aumento de los gases que se generaron con ayuda del encendedor, accionando correctamente los actuadores establecidos.

# Configuración experimental, resultados y análisis.

![image](https://github.com/user-attachments/assets/e8ba4dae-970f-4587-ba13-0aa24b34fe82)
Figura 5: Foto del montaje del Detector de Incendios.

![image](https://github.com/user-attachments/assets/40657e7e-5e57-4167-808d-fa871ef870e3)
Figura 6: Foto del montaje del Detector de Incendios.

Para llevar a cabo la correcta identificación de incendios se hizo uso de:

- Pantalla LCD 16A02
- LED-RGB
- Buzzer Passivo
- ESP32
- Sensorde gases combustibles y humo(MQ-2)
- Sensor de termperatura (ds18b20)

El color del LED indica el nivel de peligro en la zona, variando entre verde ( no presencia de gases y sin aumentos de temperatura drásticos ), amarillo (no presencia de gases pero aumento de temperatura) y rojo (Presencia de gases combustibles en la zona). Por otro lado, la pantalla LCD se encarga de mostrar la temperatura que se registra cada segundo y el nivel de alerta asociado a los colores del LED-RGB con amarillo- Aumento de temp. y rojo - ¡PELIGRO!. Además, el sistema al entrar en estado de peligro activa el buzzer emitiendo una señal de alarma.

Por cuestiones de tiempo, para el montaje no se implementó el sensor de llama puesto que las lectuas eran incoherentes inhabilitando su implementación dentro de la solución propuesta.

Con la realización del laboratorio se evidencia cómo los dispositivos IoT pueden proporcionarnos una ayuda para evitar problemas que requieren de acción inmediata, como por ejemplo, la aparición de incendios forestales en los cerros orientales de Bogotá. No solo nos permiten una identificación y medición de variables de interés temprana sino también mecanismos de acción para mitigar el impacto de dichos eventos. 


# Conclusiones y retos.
Se obtuvo un buen resultado de prototipado, los sensores y actuadores conectado presentaron un correcto funcionamiento, permitiendo así tener un dispositivo IOT que detecta de una forma efectiva distintas variables presentes en incendios, y activando los distintos actuadores en los casos necesarios. Probando su funcionamiento en distintos escenarios, obteniendo mayormente una respuesta positiva. Se encontraron también distintas limitaciones en el desarrollo del reto, como lo son el desconocimiento del uso de los sensores y su funcionamiento, por ejemplo, el sensor MQ2 requiere de un tiempo de precalentamiento para obtener lecturas precisas. Además, el principal factor limitante fue el tiempo y la poca disponibilidad de los materiales, debido a razones externas no se contó con la disponibilidad para realizar la totalidad de las pruebas. Por esto mismo, no fue posible la implementación del sensor de llama, esto a razón de el montaje y desmontaje del prototipo, lo cual provocaba problemas para el uso de los implementos.

Para una próxima práctica se espera tener una mayor disponibilidad de los implementos, y de esta forma permitir una mejor implementación para obtener resultados acordes al trabajo realizado.
