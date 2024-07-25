# Trabajo Práctico 1
La resolución del trabajo puede encontrarse en el archivo `LollapatuzaTP1.pdf`
## Enunciado
La organización del reconocido festival internacional Lollapatuza nos encomendó realizar el sistema para el manejo centralizado de la comida.

El sistema Lollapatuza debe contar con varios Puestos de Comida. Estos puestos cuentan con un `Menú` y un `Stock` de Ítems a vender. 

- El `Menú` indica el precio de cada uno de estos Ítems. Por política de la organización, se permite que dos puestos vendan un mismo Ítem, pero solo si lo venden al mismo precio. 

- El `Stock` indica la cantidad que tiene el local de cada uno de los Ítems. El local solo puede vender los Ítems de su Menú que tiene disponibles en su Stock.

Cada persona, al pasar por la caja del Puesto de Comida, puede comprar varios Ítems. 

Cada `Puesto de Comida` puede decidir implementar promociones, de la forma*“Comprando N o más cantidad del Ítem I, te hacemos X % de descuento en esos Ítems”*. Para una misma cantidad y un mismo Ítem, debe haber un único descuento, pero puede haber distintos descuentos para distintas cantidades de un mismo Ítem. En este caso, siempre se toma el descuento de mayor N. Por ejemplo, un `Puesto de Comida` puede tener los siguientes descuentos:
- Comprando 4 o más Empanadas, te hacemos 10 % de descuento en Empanadas
- Comprando 12 o más Empanadas, te hacemos 20 % de descuento en Empanadas
- Comprando 3 o más Gaseosas, te hacemos 25 % de descuento en Gaseosas

Y el siguiente Menú:
- Empanadas: $100
- Gaseosas: $200
- Hamburguesas: $1000

Asumiendo que el `Puesto de Comida` tiene `Stock` suficiente de todos estos productos, se pueden dar las
siguientes ventas:
- 4 Empanadas + 1 Gaseosas: 4 · 100 · (100−10)/100 + 1 · $200 = $560
- 12 Empanadas + 3 Gaseosas + 1 Hamburguesas: 12·$100·(100−20)/100 + 3·$200· (100−25)/100 + 1·$1000 = $2410

Lo que no sabíamos era que el grupo cuenta con un infiltrado. Justo antes de la entrega del TP, decidió incorporar la acción de `hackear` al sistema. Esta consiste en eliminar el consumo de un Ítem dado a una Persona determinada, de alguna compra en la que **NO** se le haya aplicado un descuento a este Ítem. Esta persona debería haber comprado al menos una vez dicho Ítem sin que le aplique un descuento. De existir el consumo en
múltiples puestos de comida, se eliminará el mismo de alguno de ellos, viéndose afectado su `Stock`.

Por último, el sistema Lollapatuza debe permitir ver todas las Personas que están habilitadas para realizar compras, y ver quién fue la Persona que más plata gastó. En caso de empate, se informará cualquiera de las
Personas con más gastos. Por ejemplo, dada la siguiente secuencia de acciones, tomando el `Menú` y `Promociones` de antes:
1. **Persona1** compra 3 **Empanadas** y 1 **Gaseosas** en el puesto X (por $500)
2. **Persona2** compra 4 **Empanadas** y 1 **Hamburguesas** en el puesto Y (por $1360)
3. **Persona3** compra 2 **Gaseosas** en el puesto Z (por $400)
4. Se realiza un **`hackeo`** para eliminar la compra de **Hamburguesas** a **Persona2** (restándole $1000 de su consumo total) la Persona que más plata gastó será **Persona1**. Notar que se pudo realizar el **`hackeo`** del Ítem **Hamburguesas** a **Persona2** sin importar que las **Empanadas** hayan sido cobradas con descuento.
