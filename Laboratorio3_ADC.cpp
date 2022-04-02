/*//****************************************
 // FileName:        Laboratorio3.c
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCh
 // Description:     Simulador de ADC
 // Authors:         Jorge Arnoldo Hernández Hernández
 // Updated:         01/04/2022
 //****************************************/

#include <iostream>
#include <stdlib.h>
#define MAX 33

using namespace std;

class ADC{
	
	private:
		int resolucion;
		int resl;
		int canales[MAX];
		int num;
		int frecuencia;
		float conversion;
		float voltaje [MAX];
		
	public:
		void capturar();
		void mostrar();
		float calculo(float x);
	
};


void ADC::capturar(){
	
	int i, anl;
	
	cout<<"Ingresa la resolucion (8, 12, 14 bits)"<<endl;
	cin >> resolucion;
		if(resolucion==8) resl=255;
		if(resolucion==10) resl=1023;
		if(resolucion==12) resl=4095;
		
	for (i=0;i<MAX;i++){ //Para inicializar los canales en 0 para evitar basura
		canales[i]=0;
	}
	
	cout<<"Cuantos canales desea usar?";
	cin>> num;
	
	cout<<"Ingrese la frecuencia:";
	cin>> frecuencia;
	
	for(i=0; i<num; i++){
		cout<<"Seleccione el canal a usar (max 32): AN";
		cin>>anl;
		canales[anl]=1; // Es para habilitar el canal a usar 
	}
	
	for (i=0;i<MAX;i++){
    	if (canales[i]==1){
			cout<<"Canal AN"<<i<<endl;
    	}
  	}
	
	for(i=0; i<MAX; i++){
		if(canales[i] == 1){
			cout<<"Ingresa el voltaje (max 3.3v) del AN"<<i<<":";
			cin>> conversion;
			voltaje[i]= calculo(conversion);
		}
	}
}



void ADC::mostrar(){
	int i;
	
	cout<<"\nMostrando datos";
	cout<<"\nResolucion "<<resolucion<<" bits "<<endl;
	cout<<"\nFrecuencia "<<frecuencia<<"Khz "<<endl;
	
	for(i=0; i<MAX; i++){
		if(canales[i]==1){
			cout<<"AN"<<i<<" conversion "<< voltaje[i]<<endl;
		}
	}
}

float ADC::calculo(float x){
	x = conversion/3.3*resl;
	return x;
}


int main(){
	
	float x;
	
	ADC Canal;
	
	Canal.capturar();
	Canal.mostrar();
	
	system("pause");
	
	return 0;
	
}



