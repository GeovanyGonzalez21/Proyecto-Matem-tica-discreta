//Nombre: Geovany Emmanuel González Díaz Carnet:6590-22-848
//Sección de librerias
#include<stdio.h> //Manipulación de ficheros y funciones de manipulación de entradas y salidas.
#include<conio.h> //Para utilizar el getch y pausar el sistema.
#include<stdlib.h> //Contiene los prototipos de funciones de C++.
#include<iostream> //Librería estandar de C++.
#include<math.h> //Hacer operaciones matemáticas
#include<windows.h> //Para gotoxy.
//Para acotar la función de cout.
using namespace std;
//Gotoxy nos ayuda a poder colocar el cursor en una posición indicada en la ventana donde x=columas y y=filas.
void gotoxy(int x, int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos); 
}	
//Permutaciones con repeticion.
//Se utilizaron procedimientos void para mantener un mejor orden del codigo, void no regresa ningún valor.
void PCR(){
	system("cls");
	//Se utilizaron variables long double porque para estos temas se utilizan numeros largos.
	//Sin embargo, hay problemas que el resultado ya no lo puede calcular por lo largo del mismo.
	long double prc,n,r;
	gotoxy(35,0); cout<<"-PERMUTACIONES CON REPETICION-"<<endl;
 	gotoxy(1,3); cout<<"Formula = n^r"<<endl<<endl;
	cout<<"Ingrese n: ";
	cin>>n;
	cout<<"Ingrese r: ";
	cin>>r;
	gotoxy(1,8); cout<<n<<"^"<<r<<endl;
	//Funcion para elevar n=base,r=exponente.
	prc=pow(n,r);
	cout<<endl;
	for(int i=1;i<=r;i++){
		cout<<"("<<n<<")";
	}
	//Impresion de resultado de formula.
	cout<<endl<<endl<<"Existe un total de "<<prc<<" permutaciones con repeticion para estos elementos."<<endl;
	//Getch es utilizado para tener evitar que se cierre el programa cuando terminemos las operaciones.
	getch();
}
//Permutaciones sin repeticion.
void PERMUSR(){
	system("cls");
	long double factorial=1;
	long double n;
	gotoxy(35,0); cout<<"-PERMUTACIONES SIN REPETICION-";
	gotoxy(1,2); cout<<"Formula = n!"<<endl;
	cout<<"Ingrese n: ";
	cin>>n;
	gotoxy(1,5); cout<<n<<"!"<<endl;
	for(int i=1;i<=n;i++){
		cout<<"("<<i<<")";
		factorial=factorial*i;
	}
	//Impresion de resultado de formula.
	cout<<endl<<endl<<"Existen "<<factorial<<" formas diferentes de ordenar n sin repetirse.";
	getch();
}
//Permutaciones sin repeticion de un tipo.
void PERMUSR1(){
	system("cls");
	long double factorial1=1, factorial2=1;
	long double n,r,resta,resultado;
	gotoxy(35,0); cout<<"-PERMUTACIONES SIN REPETICION DE UN TIPO-";
	gotoxy(30,2); cout<<"n!";
	gotoxy(3,3); cout<<"Formula = P(n,r) = nPr = _____";
	gotoxy(28,4); cout<<"(n-r)!"<<endl;
	cout<<"Ingrese n: ";
	cin>>n;
	cout<<"Ingrese r: ";
	cin>>r;
	cout<<endl;
	gotoxy(32,8); cout<<n<<"!";
	gotoxy(3,9); cout<<"Formula = P("<<n<<","<<r<<") = "<<n<<"P"<<r<<" = ___________";
	gotoxy(30,10); cout<<"("<<n<<"-"<<r<<")"<<endl<<endl;
	for(int i=1;i<=n;i++){
		cout<<"("<<i<<")";
		factorial1=factorial1*i;
	}
	cout<<endl;
	cout<<"_______________________________"<<endl;
	resta=n-r;
	for(int x=1;x<=resta;x++){
	factorial2=factorial2*x;
	cout<<"("<<x<<")";
}
	cout<<endl<<endl;
	resultado=factorial1/factorial2;
	//Impresion de resultado de formula.
	cout<<"Existen "<<resultado<<" diferentes de ordenar sin repetir.";
	getch();
}
//Permutaciones sin repeticion de más de un tipo.
void PERMUSR2(){
	long double n,factorial=1,resultado=1,factorialn=1,resultado2=1;
	//long long: Convertir un valor en un entero largo.
	long long resultado3;
	int numero;
	system("cls");
	gotoxy(35,0); cout<<"-PERMUTACIONES SIN REPETICION DE MAS DE UN TIPO-";
	gotoxy(23,2); cout<<"n!";
	gotoxy(3,3); cout<<"Formula = PR = _____________";
	gotoxy(20,4); cout<<"n1!n2!nk!"<<endl<<endl;
	cout<<"Ingrese el valor de n: ";
	cin>>n;
	cout<<"Ingrese el numero de elementos de n: ";
	cin>>numero;
	//Arreglo donde se guardaran las sub n.
	int elementos[numero];
	for(int i=0;i<numero;i++){
	//Se coloca la posicion i+1 porque un arreglo inicia en 0, por lo que iniciaria en n0.
		cout<<"Ingrese n"<<i+1<<": ";
		cin>>elementos[i];
	}
	//Primer for: Para hacer que se repita hasta el numero de sub n que introducimos.
	//Segundo for: Realiza el factorial de cada sub n y en factorial se va almacenando los resultados.
	//factorial al inicio vale 1.
	for(int x=0;x<numero;x++){
		for(int j=1;j<=elementos[x];j++){
			factorial=factorial*j;
		}
	}
	//La variable resultado multiplica cada factorial que se realizó.
	resultado=factorial*resultado;
	//Seguimiento de la formula;
	//Factorial de n.
	for(int a=1;a<=n;a++){
		factorialn=factorialn*a;
	}
	resultado2=factorialn/resultado;
	//Convertir resultado2 (long double) a un entero largo (long long)
	resultado3=resultado2;
	cout<<endl<<"Existen "<<resultado3<<" formas de permutacion sin repeticion.";
	getch();
}
//Combinaciones con repeticion simples.
void COMCR(){
	long double n,r,factorial1=1,factorial2=1,factorial3=1,respuesta;
	system("cls");
	gotoxy(35,0); cout<<"-COMBINACIONES CON REPETICION SIMPLE-"<<endl;
	gotoxy(27,2); cout<<"(n+r-1)!";
	gotoxy(3,3); cout<<"Formula = C(n+r-1) = ___________";
	gotoxy(27,4); cout<<"r!(n-1)!"<<endl;
	cout<<"Ingrese n: ";
	cin>>n;
	cout<<"Ingrese r: ";
	cin>>r;
	for(int i=1;i<=n+(r-1);i++){
		factorial1=factorial1*i;
	}	
	for(int x=1;x<=r;x++){
		factorial2=factorial2*x;
	}	
	for(int a=1;a<=n-1;a++){
		factorial3=factorial3*a;
	}
	//Impresion de resultado de formula.
	gotoxy(28,8); cout<<"("<<n<<"+"<<r<<"-1)!";
	gotoxy(3,9); cout<<"Formula = C("<<n<<"+"<<r<<"-1)! = ___________";
	gotoxy(28,10); cout<<r<<"!("<<n<<"-1)!"<<endl<<endl;
	respuesta=factorial1/(factorial2*factorial3);
	cout<<"El resultado es "<<respuesta<<" combinaciones con repeticion simples.";
	getch();
}
//Combinaciones con repeticion de tipo (N1*N2)
void COMSCN1N2(){
	system("cls");
	long double n1,r1,factorial=1,factorial1=1,factorial2=1,respuesta1;
	long double n2,r2,fac=1,fac1=1,fac2=1,fac3=1,respuesta2;
	system("cls");
	gotoxy(35,0); cout<<"-COMBINACIONES CON REPETICION DE TIPO (N1*N2)-"<<endl;
	gotoxy(29,2); cout<<"(n1+r1-1)!";
	gotoxy(3,3); cout<<"Formula = C1(n1+r1-1) = ___________";
	gotoxy(28,4); cout<<"r1!(n1-1)!"<<endl;
	gotoxy(62,2); cout<<"(n2+r2-1)!";
	gotoxy(43,3); cout<<"* C2(n2+r2-1) = _____________";
	gotoxy(62,4); cout<<"r2!(n2-1)!"<<endl<<endl;
	cout<<"Ingrese n1: ";
	cin>>n1;
	cout<<"Ingrese r1: ";
	cin>>r1;
	for(int i=1;i<=n1+(r1-1);i++){
		factorial=factorial*i;
	}	
	for(int x=1;x<=r1;x++){
		factorial1=factorial1*x;
	}	
	for(int a=1;a<=n1-1;a++){
		factorial2=factorial2*a;
	}
	cout<<endl;
	respuesta1=factorial/(factorial1*factorial2);
	cout<<"El resultado de combinaciones simples es de: "<<respuesta1<<endl<<endl;
	cout<<"Ingrese n2: ";
	cin>>n2;
	cout<<"Ingrese r2: ";
	cin>>r2;
	for(int z=1;z<=n2+(r2-1);z++){
		fac=fac*z;
	}	
	for(int s=1;s<=r2;s++){
		fac1=fac1*s;
	}	
	for(int b=1;b<=n2-1;b++){
		fac2=fac2*b;
	}
	respuesta2=fac/(fac1*fac2);
	cout<<endl;
	cout<<"El resultado de combinaciones simples es de: "<<respuesta2<<endl<<endl;
	//Impresion de resultado de formula.
	gotoxy(27,16); cout<<"("<<n1<<"+"<<r1<<"-1)!";
	gotoxy(3,17); cout<<"Formula = C1("<<n1<<"+"<<r1<<"-1)! = ___________";
	gotoxy(27,18); cout<<r1<<"!("<<n1<<"-1)!"<<endl;
	gotoxy(54,16); cout<<"("<<n2<<"+"<<r2<<"-1)!";
	gotoxy(36,17); cout<<" * C2("<<n2<<"+"<<r2<<"-1)  = _____________";
	gotoxy(54,18); cout<<r2<<"!("<<n2<<"-1)!"<<endl<<endl;
	cout<<"El total de combinaciones con repeticion es de: "<<respuesta1*respuesta2;
	getch();
}
//Combinaciones sin repeticion simples.
void COMSR(){
	long double n,r,factorial=1,factorial1=1,factorial2=1,respuesta;
	system("cls");
	gotoxy(35,0); cout<<"-COMBINACIONES SIN REPETICION SIMPLE-"<<endl;
	gotoxy(32,2); cout<<"n!";
	gotoxy(3,3); cout<<"Formula = C(n,r) = nCr = ___________";
	gotoxy(30,4); cout<<"r!(n-r)!"<<endl;
	cout<<"Ingrese n: ";
	cin>>n;
	cout<<"Ingrese r: ";
	cin>>r;
	cout<<endl;
	for(int i=1;i<=n;i++){
		factorial=factorial*i;
	}
	for(int y=1;y<=r;y++){
		factorial1=factorial1*y;
	}
	for(int x=1;x<=(n-r);x++){
		factorial2=factorial2*x;
	}
	cout<<endl;
	//Impresion de resultado de formula.
	gotoxy(35,8); cout<<n<<"!";
	gotoxy(3,9); cout<<"Formula = C("<<n<<","<<r<<") = "<<n<<"C"<<r<<" = ___________";
	gotoxy(30,10); cout<<r<<"!*("<<n<<"-"<<r<<")!"<<endl;
	respuesta=factorial/(factorial1*factorial2);
	cout<<endl<<"Existen "<<respuesta<<" maneras diferentes de ordenar el enunciado si no importa el orden.";
	getch();
}
//Combinaciones sin repeticion de tipo (N1*N2)
void COMSRN1N2(){
	long double n1,r1,factorial=1,factorial1=1,factorial2=1,respuesta1;
	long double n2,r2,fac=1,fac1=1,fac2=1,respuesta2;
	system("cls");
	gotoxy(35,0); cout<<"-COMBINACIONES SIN REPETICION TIPO (N1*N2)-"<<endl;
	gotoxy(35,2); cout<<"n1!";
	gotoxy(3,3); cout<<"Formula = C(n1,r1) = n1Cr1 = ___________";
	gotoxy(30,4); cout<<"r1!(n1-r1)!"<<endl;
	gotoxy(69,2); cout<<"n2!";
	gotoxy(43,3); cout<<"* C(n2,r2) = n2Cr2 = _____________";
	gotoxy(62,4); cout<<"r2!(n2-r2)!"<<endl;
	cout<<"Ingrese n1: ";
	cin>>n1;
	cout<<"Ingrese r1: ";
	cin>>r1;
	cout<<endl;
	for(int i=1;i<=n1;i++){
		factorial=factorial*i;
	}
	for(int y=1;y<=r1;y++){
		factorial1=factorial1*y;
	}
	for(int x=1;x<=(n1-r1);x++){
		factorial2=factorial2*x;
	}
	respuesta1=factorial/(factorial1*factorial2);
	cout<<endl<<"Existen "<<respuesta1<<" combinaciones simples."<<endl<<endl;
	cout<<"Ingrese n2: ";
	cin>>n2;
	cout<<"Ingrese r2: ";
	cin>>r2;
	cout<<endl;
	for(int p=1;p<=n2;p++){
		fac=fac*p;
	}
	for(int u=1;u<=r2;u++){
		fac1=fac1*u;
	}
	for(int c=1;c<=(n2-r2);c++){
		fac2=fac2*c;
	}
	respuesta2=fac/(fac1*fac2);
	cout<<endl<<"Existen "<<respuesta2<<" combinaciones simples."<<endl;
	//Impresion de resultado de formula.
	gotoxy(35,17); cout<<n1<<"!";
	gotoxy(3,18); cout<<"Formula = C("<<n1<<","<<r1<<") = "<<n1<<"C"<<r1<<" = ___________";
	gotoxy(30,19); cout<<r1<<"!*("<<n1<<"-"<<r1<<")!"<<endl;
	gotoxy(69,17); cout<<n2<<"!";
	gotoxy(43,18); cout<<"* C("<<n2<<","<<r2<<") = "<<n2<<"C"<<r2<<" = _____________";
	gotoxy(62,19); cout<<r2<<"!*("<<n2<<"-"<<r2<<")!"<<endl<<endl;
	cout<<endl<<"La combinacion de la forma (N1*N2) es = "<<respuesta1*respuesta2;
	getch();
}
void menu(){
	//Menu principal.
	system("cls");
	cout<<"Geovany Emmanuel Gonzalez Diaz - Carnet: 6590-22-848";	
	gotoxy(35,2); cout<<"-PROYECTO DE PERMUTACIONES Y COMBINACIONES-"<<endl<<endl;
	cout<<"1. Permutaciones con repeticion:"<<endl;
	cout<<"2. Permutaciones sin repeticion:"<<endl;
	cout<<"3. Permutaciones sin repeticion de un tipo:"<<endl;
	cout<<"4. Permutaciones sin repeticion de mas de un tipo:"<<endl;
	cout<<"5. Combinaciones con repeticion simple:"<<endl;
	cout<<"6. Combinaciones con repeticion de tipo (N1*N2):"<<endl;
	cout<<"7. Combinaciones sin repeticion simples:"<<endl;
	cout<<"8. Combinaciones sin repeticion de tipo (N1*N2):"<<endl;
	cout<<"9. Salir:"<<endl<<endl;
	cout<<"Bienvenido, selecciona la opcion que necesites trabajar: ";
}
//Función principal.	
main(){
	//Cambiar color de fondo y letra. El primer caracter es el color de fondo y el segundo es el color de letra.
	system("COLOR B0");
	int opcion;
	//Se utilizo el ciclo do while para garantizar que se repita por lo menos una vez.
	do{
		menu();
		cin>>opcion;
		switch(opcion){
			case 1:
				//Permutaciones con repeticion.
				PCR();
			break;
			case 2:
				//Permutaciones sin repeticion
				PERMUSR();
			break;
			case 3:
				//Permutaciones sin repeticion de un tipo.
				PERMUSR1();
			break;
			case 4:
				//Permutaciones sin repeticion de mas de un tipo.
				PERMUSR2();
			break;	
			case 5:
				//Combinaciones con repeticion simples
				COMCR();
			break;
				//Combinaciones con repeticion de tipo (N1*N2).
			case 6:
				COMSCN1N2();
			break;
				//Combinaciones sin repeticion simples.
			case 7:
				COMSR();
			break;
			case 8:
				//Combinaciones sin repeticion de tipo (N1*N2).
				COMSRN1N2();
			break;
			case 9:
				cout<<endl<<"Hasta pronto!";
				getch();
			break;
		}
	//Mientras opcion no sea igual a 9, que es "hasta pronto" lo que significa cerrar el programa.
	}while(opcion!=9);
}
