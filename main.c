#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
int inventario();

int trasaccion()
{
    int valor=0;
    printf("\nIngrese cantidad: ");
    scanf("%d",&valor);
    return valor;
}

int main()
{
    FILE *archivo;

    int lanzoprazol=50, ibuprofen=10, aceptaminofen=10, budena=50, salbutamol=20;//Variables Invetrario Inicial.
    int opcion=0, medicina=0, cantidad=0;//Variables extras.
    char informacion[100];
    int nitProveedor[14];//Variables de Datos del cliente o Proveedor
    char nitCliente[14];
    char fechayhora;
    char nombre_archivo[11]="archivo.txt";//Archivo de texto donde se guardara información

    printf("\n****************************** EMILY DRUGSTORE I ******************************\n\n");
    do
    {
        printf("Inventario Actual en Farmacia:\n\n|*Medicamento*| |*Cantidad*| |*Precio Q.*|\n| Lanzoprazol | |    %d    | |     1     |\n|  Ibuprofen  | |    %d    | |     2     |\n|Aceptaminofen| |    %d    | |     3     |\n|   Budena    | |    %d    | |     20    |\n| Salbutamol  | |    %d    | |     25    |\n\n",lanzoprazol,ibuprofen,aceptaminofen,budena,salbutamol);
       opcion=menu();
       archivo= fopen(nombre_archivo,"a");
       switch (opcion)
       {
            case 1:
                printf("\n*** COMPRA DE MEDICAMENTO ***");//Algoritmo para aumentar Inventario
                printf("\nIngrese NIT: ");//Datos del Cliente, Proveedor
                //Guardar archivo.txt
                //archivo= fopen(nombre_archivo,"w+");
                memset(nitProveedor,0,14);
                scanf("%s",&nitProveedor);
                fputs("\n*** Información de Compra ***\nNit del Proveedor: ",archivo);
                fwrite(nitProveedor, sizeof(unsigned char),strlen(nitProveedor),archivo);
                medicina=inventario();//Transacción
                    switch(medicina)
                    {
                    case 1:
                        cantidad=trasaccion();
                        lanzoprazol=lanzoprazol+cantidad;
                        fputs("\nSe compro Lanzaprazol, unidades: ",archivo);
                        fprintf(archivo,"%d",cantidad);
                        break;
                    case 2:
                        cantidad=trasaccion();
                        ibuprofen=ibuprofen+cantidad;
                        break;
                    case 3:
                        cantidad=trasaccion();
                        aceptaminofen=aceptaminofen+cantidad;
                        break;
                    case 4:
                        cantidad=trasaccion();
                        budena=budena+cantidad;
                        break;
                    case 5:
                        cantidad=trasaccion();
                        salbutamol=salbutamol+cantidad;
                    }
                /**/
                //fclose(archivo);
                break;

            case 2:
                printf("\n*** VENTA DE MEDICAMENTO ***");//Algoritmo para disminuir Inventario
                //Datos del Cliente, Proveedor
                medicina=inventario();//Transacción
                    switch(medicina)
                    {
                    case 1:
                        cantidad=trasaccion();
                        lanzoprazol=lanzoprazol-cantidad;
                        break;
                    case 2:
                        cantidad=trasaccion();
                        ibuprofen=ibuprofen-cantidad;
                        break;
                    case 3:
                        cantidad=trasaccion();
                        aceptaminofen=aceptaminofen-cantidad;
                        break;
                    case 4:
                        cantidad=trasaccion();
                        budena=budena-cantidad;
                        break;
                    case 5:
                        cantidad=trasaccion();
                        salbutamol=salbutamol-cantidad;
                    }
                break;

            case 3:
                printf("\n*** TRASLASDO DE MEDICAMENTO ***");//Algoritmo para disminuir Inventario
                //Datos del Cliente, Proveedor
                medicina=inventario();//Transacción
                    switch(medicina)
                    {
                    case 1:
                        cantidad=trasaccion();
                        lanzoprazol=lanzoprazol-cantidad;
                        break;
                    case 2:
                        cantidad=trasaccion();
                        ibuprofen=ibuprofen-cantidad;
                        break;
                    case 3:
                        cantidad=trasaccion();
                        aceptaminofen=aceptaminofen+cantidad;
                        break;
                    case 4:
                        cantidad=trasaccion();
                        budena=budena-cantidad;
                        break;
                    case 5:
                        cantidad=trasaccion();
                        salbutamol=salbutamol-cantidad;
                    }
       }
       fclose(archivo);
    } while(opcion!=4);

    return 0;
}

//Menu
int menu()//Función para seleccionar el tipo de transacción a realizar en la farmacia.
{
    int opcion=0;
    printf("\n ****** MENU PRINCIPAL ***** \n\nIngrese el numero de la transaccion que desea realizar: \n 1. Compra de Medicina \n 2. Venta de Medicina \n 3. Traslados de Medicina \n 4. Salir\n* Opcion: ");
    scanf("%d",&opcion);
    return opcion;
}

//Inventario
int inventario()//Funcion seleccionar un medicamento.
{
    int opcion=0;
    printf("\n\n***** INVENTARIO *****\n\nIngrese el numero del medicamento que desee:\n 1. Lanzoprazol\n 2. Ibuprofen\n 3. Aceptaminofen\n 4. Budena\n 5. Salbutamol\n * Opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
