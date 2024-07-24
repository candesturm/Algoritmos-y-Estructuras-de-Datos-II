El objetivo de este TP es implementar en C++ todos los módulos correspondientes al diseño presentado
por su grupo en el TP2. El código que entreguen debería respetar el diseño propuesto en el TP2 de la manera
más fiel posible. Obviamente se permite y se espera que corrijan todos los potenciales bugs que puedan llegar
a encontrar en el diseño. Las implementaciones deben cumplir con las complejidades definidas en su solución
del TP 2 (salvo mejoras que hayan encontrado), incluyendo las restricciones de complejidad establecidas en el
enunciado del mismo.
Código producido
La resolución debe tener un archivo .h y .cpp por cada módulo del TP 2 (o eventualmente un archivo .hpp
si se trata de un módulo paramétrico que se implemente con templates). Estos archivos deberán ubicarse en
el directorio src, respetando el esqueleto disponible en la página de la materia.
Código de la cátedra y tests
Como parte del enunciado, la cátedra provee un esqueleto de TP3. El esqueleto tiene la misma estructura
de directorio que los talleres, con un directorio src para los archivos fuente y un directorio tests para el código
de los tests. Proveemos un conjunto de casos de test que deberán ser pasados con éxito. Los tests provistos por
la cátedra no son necesariamente exhaustivos, por lo tanto, deben escribir sus propios tests de unidad para
evaluar aquellos casos que no estén contemplados en los tests de la cátedra. Se exige para la aprobación del TP
haber incluido al menos 1 test propio.
Los archivos que comienzan con el prefijo fachada_ que se encuentran en el directorio src son provistos
como parte del esqueleto del TP para poder utilizarlos en los tests. Deben completar estos archivos agregando
instancias de las clases diseñadas por ustedes en la parte privada de cada clase e implementado los métodos de
forma tal que utilicen la interfaz provista por sus propios módulos.
El archivo src/tipos.h define algunos tipos auxiliares y renombres de tipos. En particular, se define el
struct aed2_Puesto. Este struct agrupa los parámetros que se necesitan para crear un puesto y sú único
próposito es para facilitar los tests de la cátedra.
La adaptación de la interfaz de sus módulos a los requeridos en en las fachadas puede conllevar operaciones
con un costo no inmediato (ej. copiar un conjunto a una lista, recorrer un diccionario, etc.). Los requisitos de
complejidad a cumplir aplican solamente a las funciones de la interfaz de los módulos. Los costos asociados a
la traducción de su interfaz a la nuestra no tienen restricciones.

Importante: sugerimos implementar la menor lógica posible en los archivos Fachada, y crear clases independientes que respeten el diseño hecho por ustedes en el TP1. Estas clases se llaman “Fachada” porque deberían
delegar todos los mensajes que reciben a las clases diseñadas por ustedes. Así, la implementación de todos los
métodos de las clases Fachada_ debería ser breve (ej. una o dos líneas).
