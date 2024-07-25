<h1 align="center"> Trabajo Práctico 2: Diseño </h1>
Este TP desarrollado en el archivo **`LollapatuzaTP2.pdf`** consiste en diseñar módulos para implementar el sistema del Lollapatuza, conforme a la especificación que estará disponible en **`especificacion.pdf`**.
Se deben proveer las siguientes operaciones, con las complejidades temporales en peor caso indicadas.
Usamos las siguientes variables:

-    A - cantidad de personas
-    I - cantidad total de ítems en todo el festival
-    P - cantidad de puestos 


<h2> 1.1 Lollapatuza </h2>
1. Iniciar un nuevo sistema. *No se pone restricción a la complejidad*.
2. Registrar la compra de una cantidad de un ítem particular, realizada por una persona en un puesto.
**O(log(A) + log(I) + log(P) + log(cant))**. Donde cant corresponde a la cantidad adquirida del ítem que
compró la persona en esta transacción.
3. Hackear un ítem consumido por una persona. Se hackea el puesto de menor ID en el que la persona
haya consumido ese ítem sin promoción. **O(log(A) + log(I))**. En caso de que el puesto correspondiente
deje de ser hackeable para esa persona e ítem luego de esta operación, se permitirá una complejidad de
** O(log(A) + log(I) + log(P))** .
4. Obtener el gasto total de una persona. **O(log(A))**.
5. Obtener la persona que más dinero gastó. Si hay más de una persona que gastó el monto máximo,
desempata por ID de la persona. **O(1)**.
6. Obtener el ID del puesto de menor stock para un ítem dado. Si hay más de un puesto que tiene stock
mínimo, dar el de menor ID. *No se pone restricción a la complejidad*.
7. Conocer la información general del sistema:
Obtener las personas. **O(1)**.
Obtener los puestos de comidas, con sus IDs. **O(1)**.
8. Otras operaciones que crean conveniente agregar al módulo. *No se pone restricción a la complejidad*.

<h2> 1.2. Puesto de Comida </h2>

1. Inicializar un nuevo puesto. *No se pone restricción a la complejidad*.
2. Obtener el stock de un ítem. **O(log(I))**.
3. Obtener el descuento de un ítem dada la cantidad del mismo. **O(log(I) + log(cant))**. Donde cant es la
cantidad del ítem.
4. Obtener el gasto realizado por una persona en el puesto. **O(log(A))**.
5. Otras operaciones que crean conveniente agregar al módulo. *No se pone restricción a la complejidad*
