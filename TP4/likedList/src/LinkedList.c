#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;

	this = (LinkedList*)malloc(sizeof(LinkedList)); //reservas memoria para el nodo
	if (this != NULL)
	{
		this->pFirstNode = NULL; //ult = NULL
		this->size = 0;
	}
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if(this != NULL)
	{
		returnAux = this->size;
	}

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodeAux = NULL; //es el nodo a retornar

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) //preguntar por que el nodeIndex no puede ser <= ll_len --> porque es como los arrays
	{
		pNodeAux = this->pFirstNode; //es el caso del nodeIndex = 0
		for(int i = 0; i < nodeIndex; i++)
		{
			pNodeAux = pNodeAux->pNextNode;
			//iteras para conseguir el siguiente nodo, lo vas guardando en el pBufferNode
		}
	}

    return pNodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	//creo el nodo
    int returnAux = -1;
    Node* newNode;
    Node* prevNode;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) //<= a ll_len porque por ej tengo 5 elementos, y agrego un elemento--> queda en el indice 5 (indice 0, 1, 2, 3, 4 -> +1 --> 0, 1, 2, 3, 4, 5)
    	//todas las colecciones en cualquier lenguaje indexan en 0
    	//cuando agregas alñgo lo podes agregar en la ult posic = arrays
    {
    	newNode = (Node*)malloc(sizeof(Node));
    	if(newNode != NULL)
    	{
			if(nodeIndex == 0) //si es el primer nodo
			{
				//es independiente de donde lo quieras agregar, siempre se conecta al anterior
				//nuevo -->apunta al ant
				//ll -->apunta al nuevo
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
				//esto lo hago por si hago, por ej, un push
			}
			else
			{
				prevNode = getNode(this, nodeIndex-1); //obtengo el nodo anterior
				if(prevNode != NULL)
				{
					//nuevo -->apunta al ant
					//viejo --> apunta al nuevo
					newNode->pNextNode = prevNode->pNextNode;//me guardo el next node en el nuevo
					prevNode->pNextNode = newNode;//pNextNode = ESTE NODO
				}
			}
			newNode->pElement = pElement;
			//pElement = no puede ser nulo porque puedo reservar espacio en memoria para un nodo simplemente
			this->size++; //Incremento el tamaño de la linkedlist
			returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	//agrego el elemento a la lista (1 nodo = 1 elemento)
	//agrega en la ultima posic
	int returnAux = -1; //borrar
	if(this != NULL)
	{
		if(addNode(this, ll_len(this), pElement) == 0)//Agrega un nodo al final --> null = 0
		{
			returnAux = 0; //agregar al retorno el addnode
		}
	}
	return returnAux;
}

/** \brief Devuelve el puntero al elemento del indice recibido
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	//para obtener un elemento (empleado, por ej) en det indice
    void* returnAux = NULL;
    Node* pNodeAux;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodeAux = getNode(this,index); //porque quiero obtener el nodo que contiene el elemento que en el indice que quiero
    	if(pNodeAux != NULL)
    	{
    		returnAux = pNodeAux->pElement; //accedo al elemento y lo retorno
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	//pisa la posicion
	int returnAux = -1;
	Node *pNodeAux;

	if (this != NULL && index >= 0 && index < ll_len(this)) //5 --> 0, 1, 2, 3, 4
	{
		pNodeAux = getNode(this, index); //obtengo el nodo
		if (pNodeAux != NULL)
		{
			pNodeAux->pElement = pElement; //accedo al elemento para modificarlo
			returnAux = 0;
		}
	}
	return returnAux;
}


/** \brief Elimina un elemento de la lista (nodo)
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
	//elimino un NODO de la lista
	//el elemento de ese nodo no es eliminado
    int returnAux = -1;
    Node* pNodeAux;
    Node* pPrevNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
		pNodeAux = getNode(this, index); //me trae el nodo de indice 0 que apunta a la direccion de memoria del siguiente nodo
										 // pNodeAux = nodo 0
		if(pNodeAux != NULL)
		{
			if(index == 0) //si es el primer elemento
			{
				this->pFirstNode = pNodeAux->pNextNode; //el pfirstnode pasa a apuntar a la direccion de memoria del nodo 1 (la direccion de memoria del nodo 1 la tiene el nodo 0)
			}
			else
			{
				pPrevNode = getNode(this,index-1); //obtengo el nodo anterior
				if(pPrevNode != NULL)
				{
					pPrevNode->pNextNode = pNodeAux->pNextNode; //hago que el nodo previo apunte a la direccion de memoria del siguiente nodo (esa direccion de memoria la tiene el pNodeAux)
				}
			}
			free(pNodeAux); //se elimina el nodo pero no el elemento
			//la lista no maneja el dato porque otras listas pueden estar apuntando al mismo dato --> delete_employee
			this->size--;
			returnAux = 0;
		}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	//REVISAR
	//vacia la ll pero luego puedo meter empleados de nuevo
	int returnAux = -1;

	    if(this != NULL)
	    {
			for(int i = 0; i == 0 || i < ll_len(this); i++) //elimina todos los nodos de la lista --> hace un ll_remove de todos los elementos de la lista
			{
				ll_remove(this, i);
				returnAux = 0;
			}
	    }
	    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	//vacia la ll (elimina todos sus nodos con ll_clear) y ademas elimina la ll
    int returnAux = -1;

    if(this != NULL)
    {
		if(ll_clear(this) == 0) //elimina todos los nodos
		{
			free(this); //con el free elimino todos los elementos? o elimino simplemente la ll?
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	//le pasas el elemento y le preguntas que indice tiene ese elemento
	//a diferencia del ll_get que le das un indice y te va a buscar el elemento
    int returnAux = -1;
    void* pElementAux;

    if(this != NULL)
    {
		for(int i = 0; i < ll_len(this); i++)
		{
			pElementAux = ll_get(this, i); //obtiene un elemento en determinado indice
			if(pElementAux == pElement) //te fijas si coinciden el elemento que encontraste con el que buscas
			{
				returnAux = i; //si coincide retorno el indice
				break;
			}
		}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
	{
    	returnAux = 0; //no vacia
    	//la lista esta llena hasta que se demuestre lo contrario
		if(ll_len(this) == 0) // vacia
		{
			returnAux = 1; // vacia
		}

	}
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	//para agregar en una posicion y que no se pise
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(addNode(this, index, pElement) == 0) //agrego en esa posicion especifica
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	//devuelve el empleado que se elimino
	//si quiero mostrar el elemento que acabo de eliminar
	//si quiero mandar el empleado a otra lista
    void* returnAux = NULL;
    void* pElementAux;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pElementAux = ll_get(this, index); //obtiene un elemento en determinado indice
		//if (pElementAux != NULL) NO PORQUE PUEDE HABER NULLS EN LA LINKEDLIST
		//{
			if(ll_remove(this, index) == 0)
			{
				returnAux = pElementAux;
			}
		//}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0; //no lo contiene
		if(ll_indexOf(this,pElement) != -1) //busca el indice del elemento
		{
			returnAux = 1; //si lo contiene
		}

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
	int returnAux = -1;
	void* pElement;
	int i;

	if(this != NULL && this2 != NULL)
	{
		returnAux = 1; //todos los elementos de this2 estan en this
		for(i = 0; i < ll_len(this2); i++)
		{
			pElement = ll_get(this2, i); //obtiene un elemento en determinado indice
			if(ll_contains(this, pElement) == 0)//si el elemento no esta
			{
				returnAux = 0; //los elem de this2 no estan en this
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
	//para clonar la lista desde X elemento hasta Y elemento (me devuelve una parte de la lista)
	//to = lo excluye
    LinkedList* cloneArray = NULL;
    void* pElement;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList(); //creo una nueva ll
    	if (cloneArray != NULL)
    	{
			for(int i = from; i < to; i++) //voy desde X elem hasta Y elem, excluyendo Y
			{
				pElement = ll_get(this, i); //obtiene un elemento en determinado indice
				ll_add(cloneArray, pElement); //agrega el elemento a la lista clon
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	//clona toda la lista
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this)); //desde 0 hasta el ult elem
    	//si hago clone = this --> apunto al mismo lugar | "mato la primera lista"
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
	int disorderedState = 1;
	int criteria;
	void* pElement;
	void* pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		while (disorderedState)
		{
			disorderedState = 0;
			for (int i = 0; i < ll_len(this)- 1; i++)
			{
				pElement = ll_get(this, i); //obtiene un elemento en indice
				pElement2 = ll_get(this, i+1); //obtiene un elemento en indice+1
				criteria = pFunc(pElement,pElement2); //determina si se hace o no un swap
				if ((order == 1 && criteria == 1) ||
					(order == 0 && criteria == -1)) //-1 no hace swap?
				{
					ll_set(this, i, pElement2); //modifica elem de la lista
					ll_set(this, i+1, pElement);
					disorderedState = 1;
				}
			}
		}
		returnAux = 0;
	}
    return returnAux;

}

