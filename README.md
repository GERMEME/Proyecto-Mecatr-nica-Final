# Proyecto-Mecatr-nica-Final
En el presente repositorio se presentan los códigos y material utilizado para la realización del proyecto de Mecatrónica Otoño 2024.

En el avance 1 se realizó: Código Avance 1 (Alexis Pinto),
                           Montaje circuito en Arduino UNO (Matías Ramírez),
                           CAD de la grua torre (Germán Oteíza).

En el avance 2: Simulación en Tinkercad de circuito (Germán Oteíza),
                Código Avance 2 (Germán Oteíza),
                Ajustes de CAD grua torre (Germán Oteíza),
                Informe formato científico (Germán Oteíza).

Detalles AVANCE 1:
En principio la idea es realizar una grúa torre en la cual la torre principal pudiera rotar en su eje, y además, en el brazo de trabajo de la grúa exitiera un gancho el cual pudiera subir y bajar para tomar objetos. Para ello se debió realizar un diseño completo desde cero de la grúa debido a que los CAD disponibles en internet poseían estructuras muy finas que no servían para su posterior impresión, los componentes utilizados en el avance 1 contemplan el uso de Arduino UNO con su placa de trabajo, dos motores DC N20, un puente H y un joystick, el código hecho para hacer funcionar el joystick es simple y se encarga de lograr que el motor DC N20 cambie su dirección de rotación al mover el joystick en una dirección predeterminada, en esta presentación no existe simulación en tinkercad, ya que en ese momento no se entendía como simular el joystick. La presentación de avance 1 cumple con los objetivos planteados en aquel momento.

Detalles AVANCE 2:
Para el avance 2 se decide eliminar la carretilla que anteriormente subía y bajaba el gancho, con el objetivo de implementar en el brazo de trabajo de la torre un carril que pueda transportar el gancho en el eje X, de esa forma recorre el brazo y no está limitado a tomar cosas solo por el extremo de este. La implicancia de este cambio en el código se refleja en que ahora se debe controlar mejor la velocidad con la que actúan los motores DC N20, en este punto se decide agregar un sensor de ultrasonido en el extremo del eje X, el objetivo es que detecte el gancho recorriendo el carril, de esta forma si el gancho se aleja más de 40cm el sensor apaga el motor, si el gancho se acerca a menos de 10cm el sensor también apaga el motor con un delay de 1 segundo. Así se logra impedir que el carrito choque con los extremos al momento de funcionar. Para observar estos cambios se realizó el código y la simulación en tinkercad.

Link circuito tinkercad: https://www.tinkercad.com/things/bKWTbXuGWnP-spectacular-duup/editel?sharecode=sZ5sTkJBvH_FG0I9vhqKgpmlNchFRnstBd5u6dH9_4U

MEJORAS FUTURAS:
Mejorar el sistema de carril implementado en el Avance 2 para desplazar el gancho en el eje X, ya que el diseño modelado en 3D presenta fallas en su funcionamiento. Además sería interesante agregar un sensor de presión o fuerza en el gancho para detectar si está tomando un objeto, determinar cuanto pesa y de esta forma determinar un peso de trabajo máximo para la grúa. Nuevamente respecto al CAD hacer más grandes los contrapesos de la grúa ubicados en la base y en el brazo de trabajo, ya que el resultado post impresión es un poco pequeño y el PLA es un material bastante ligero, por lo que no se compensa bien la fuerza siempre. Respecto al código, en general funciona bien, sin embargo en el rango mayor a 40cm la velocidad está seteada en 0, pero en ocasiones marca 1, creo que se debe a un choque entre condiciones con los ajustes de velocidad, en un momento logré arreglarlo, pero volvió a ocurrir al cambiar otros detalles.

Gracias por leer!!!
