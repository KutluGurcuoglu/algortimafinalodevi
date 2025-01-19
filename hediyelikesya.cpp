#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>

using namespace std;

struct HediyelikEsya
{
	char kod[5];
	char ad[300];
	char tur[200];
	char fiyat[99999];	
	char cinsiyet;
};
void EsyaEkle();
void EsyaListeleme();
void EsyaArama();
void EsyaSil();
void EsyaDuzenle();

int main(){
	
	char menu;
	do{
	system("cls");
	
	cout << "|-------Hosgeldiniz-------|\n";
	cout << "|      Secim Yapiniz      |\n";
	cout << "|   1-   Esya Ekleme      |\n";
	cout << "|   2-   Esya Listeleme   |\n";
	cout << "|   3-   Esya Arama       |\n";
	cout << "|   4-   Esya Sil         |\n";
	cout << "|   5-   Esya Duzenle     |\n";
	cout << "|-------------------------|\n";
    char secim;
	cin>> secim;
	
	switch(secim) 
	{
		case '1' : 
		{
		EsyaEkle();
		break;	
		}
		case '2' : 
		{
		 EsyaListeleme()	;
		 break;
		}
		case '3' : 
		{
		 EsyaArama()	;
		 break;
		}
		case '4' : 
		{
		 EsyaSil()	;
		 break;
		}
		case '5' : 
		{
		 EsyaDuzenle();
		 break;
		}
	}
	
	cout << "Menuye donmek icin m tusuna cikmak icin: c tusuna basiniz\n" ; 
	menu=getche();
	
    }while(menu=='m'||menu=='M');
     

return 0;
}

HediyelikEsya esya;

void EsyaEkle()
{
	ofstream esyadbyaz("esya.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
	
	do{
	cout << "Esya kodunu giriniz(4 haneli ornek: 1111)\n";
	cin>> esya.kod;
	cin.clear();
	cout << "Esya adini giriniz\n";
	cin>>esya.ad;
	cin.clear();
	cout << "Esya turunu giriniz\n";
	cin>> esya.tur;
	cout << "Esya fiyatini giriniz\n";
	cin>> esya.fiyat;
	cout << "Esya cinsiyetini giriniz (E/K/U(Uniseks)))\n";
	esya.cinsiyet=getche();
	cout << endl;
	esyadbyaz.write((char*)&esya, sizeof(esya));	
	adet++;	
	cout << "Yeni kayit eklemek istermisiniz (E/H)\n";
	secim=getche();
	cout << endl;
	}while(secim=='e' || secim=='E');
	
	cout << adet << " adet eysa eklendi..\n";
	
	esyadbyaz.close();
	
	
}

void EsyaListeleme()
{
	
	ifstream esyadboku("esya.dat",ios::binary |ios::app);
	
	esyadboku.seekg(0,ios::end);
	int kayits=esyadboku.tellg()/sizeof(esya);
	cout << "Toplam Esya Kayit Sayisi:"<< kayits << endl;
	
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			esyadboku.seekg(i*sizeof(esya));
			esyadboku.read((char*)&esya, sizeof(esya));	
		
			cout << i+1 << ". Esyanin Bilgileri"<< endl;
			cout << "Esyanin Kodu: "<< esya.kod <<endl ;
			cout << "Esyanin Adi: "<< esya.ad <<endl ;
			cout << "Esyanin Turu: "<< esya.tur <<endl ;
			cout << "Esyanin Fiyati: "<< esya.fiyat <<endl ;
			if(esya.cinsiyet=='e' || esya.cinsiyet=='E')
			{
				cout << "Esya Cinsiyet: Erkek\n";
			}
			else if(esya.cinsiyet=='k' || esya.cinsiyet=='K')
			{
				cout << "Esya  Cinsiyet: Kadin\n";
			}
			else if(esya.cinsiyet=='u' || esya.cinsiyet=='U')
			{
				cout << "Esya Cinsiyet: Uniseks\n";
			}
			
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	esyadboku.close();
}
void EsyaArama()
{
	
	ifstream esyadboku("esya.dat",ios::binary |ios::app);
	
	esyadboku.seekg(0,ios::end);
	int kayits=esyadboku.tellg()/sizeof(esya);


cout <<"Aranan Esya kodunu giriniz\n";
char kod[5];
cin>> kod;
 		
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			esyadboku.seekg(i*sizeof(esya));
			esyadboku.read((char*)&esya, sizeof(esya));	
		
			if(strcmp(esya.kod,kod)==0)
			{
			cout << i+1 << ". Esyanin Bilgileri"<< endl;
			cout << "Esyanin Kodu: "<< esya.kod <<endl ;
			cout << "Esyanin Adi: "<< esya.ad <<endl ;
			cout << "Esyanin Turu: "<< esya.tur <<endl ;
			cout << "Esyanin Fiyati: "<< esya.fiyat <<endl ;
			if(esya.cinsiyet=='e' || esya.cinsiyet=='E')
			{
				cout << "Esya Cinsiyet: Erkek\n";
			}
			else if(esya.cinsiyet=='k' || esya.cinsiyet=='K')
			{
				cout << "Esya  Cinsiyet: Kadin\n";
			}
			else if(esya.cinsiyet=='u' || esya.cinsiyet=='U')
			{
				cout << "Esya Cinsiyet: Uniseks\n";
			}
		    }
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	esyadboku.close();
}

void EsyaSil()
{
	 char esyakod[5];
     char secim= ' ';
     bool var=false;
     
    ifstream esyadboku("esya.dat",ios::binary |ios::app);
	
	esyadboku.seekg(0,ios::end);

	int kayitsayisi=esyadboku.tellg()/sizeof(esya);
	
     cout<<"Kaydini sileceginiz esya kodunu giriniz : ";
     cin>>esyakod;

     for(int i=0;i<kayitsayisi;i++)
     {
            esyadboku.seekg(i*sizeof(esya));
			esyadboku.read((char*)&esya, sizeof(esya));
			
     if(strcmp(esya.kod,esyakod)==0)
       {
            cout<<endl;
            cout<<"Esyanin";
            cout<<"\nKodu : "<<esya.kod;
            cout<<"\nAdi : "<<esya.ad<<endl;
            cout<<"\nTuru : "<<esya.tur;
            cout<<"\nFiyati : "<<esya.fiyat;
            cout<<"\nCinsiyet [E/K/U]: ";
            if(esya.cinsiyet=='e' || esya.cinsiyet=='E')
			{
				cout << "Esya Cinsiyet: Erkek\n";
			}
			else if(esya.cinsiyet=='k' || esya.cinsiyet=='K')
			{
				cout << "Esya  Cinsiyet: Kadin\n";
			}
			else if(esya.cinsiyet=='u' || esya.cinsiyet=='U')
			{
				cout << "Esya Cinsiyet: Uniseks\n";
			}         	 				  
            cout<<"\n\nSilmek istediginiz kayit bu mu? [E/H] : ";
            secim=getche();
            if(secim == 'H' || secim == 'h')
            {      
		    	HediyelikEsya yedekesya;
                ofstream yedekdb("yedek.dat",ios::app|ios::binary);
                
                strcpy(yedekesya.kod,esya.kod);
                strcpy(yedekesya.ad,esya.ad);
                strcpy(yedekesya.tur,yedekesya.tur);
                strcpy(yedekesya.fiyat,esya.fiyat);
                esya.cinsiyet=yedekesya.cinsiyet;
                        
                yedekdb.write((char*)&esya, sizeof(esya));
                yedekdb.close();
              }
            if(secim=='e'||secim=='E')
            {
   			   	var=true;
  		 	}
        }
            else
            {
           	  	HediyelikEsya yedekesya;
              	ofstream yedekdb("yedek.dat",ios::app|ios::binary);              
              	strcpy(yedekesya.kod,esya.kod);
            	strcpy(yedekesya.ad,esya.ad);
            	strcpy(yedekesya.tur,yedekesya.tur);
                strcpy(yedekesya.fiyat,esya.fiyat);
                esya.cinsiyet=yedekesya.cinsiyet;
                       
              	yedekdb.write((char*)&esya, sizeof(esya));
              	yedekdb.close();
             }
     }
    esyadboku.close();
    if(var)
    {
               remove("esya.dat");
               rename("yedek.dat","esya.dat");
               cout<<"\n Kayit Silindi"<<endl;
    }
    else
    {
               remove("yedek.dat");
               cout<<"\n Kayit silinmedi"<<endl;                  
    }
	
	
}

void EsyaDuzenle()
{
	 char esyakod[5];
     char secim= ' ';
     bool var=false;
     
    ifstream esyadboku("esya.dat",ios::binary |ios::app);
	
	esyadboku.seekg(0,ios::end);

	int kayitsayisi=esyadboku.tellg()/sizeof(esya);
		
     cout<<"Kaydini duzenleyeceginiz esya kodunu giriniz : ";
     cin>>esyakod;

	ofstream yedek("yedek.dat",ios::binary);

     for(int i=0;i<kayitsayisi;i++)
     {
            esyadboku.seekg(i*sizeof(esya));
			esyadboku.read((char*)&esya, sizeof(esya));
			
     		if(strcmp(esya.kod,esyakod)==0)
     		  {
     		  	
                cout<<endl;
	            cout<<"Esyanin";
	            cout<<"\nKodu : "<<esya.kod;
	            cout<<"\nAdi : "<<esya.ad<<endl;
	            cout<<"\nTuru : "<<esya.tur;
	            cout<<"\nFiyati : "<<esya.fiyat;
	            cout<<"\nCinsiyet [E/K/U]: ";
	            if(esya.cinsiyet=='e' || esya.cinsiyet=='E')
				{
					cout << "Esya Cinsiyet: Erkek\n";
				}
				else if(esya.cinsiyet=='k' || esya.cinsiyet=='K')
				{
					cout << "Esya  Cinsiyet: Kadin\n";
				}
				else if(esya.cinsiyet=='u' || esya.cinsiyet=='U')
				{
					cout << "Esya Cinsiyet: Uniseks\n";
				}         	 				 
                 
                cout<<"\n\nDuzeltmek istediginiz kayit bu mu? [E/H] : ";
                secim=getche();
                if(secim == 'E' || secim == 'e')
                {
                 	var=true;
                    ofstream dosya("yedek.dat",ios::app|ios::binary);
                    cout << "\nEsya kodunu giriniz" << endl;
					cin>> esya.kod;
					cout << "Esya adini giriniz" << endl;
					cin>> esya.ad;
					cout << "Esya turunu giriniz" << endl;
					cin>> esya.tur;
					cout << "Esya fiyat giriniz" << endl;
					cin>> esya.fiyat;
					cout << "Esya cinsiyetini giriniz (E/K/U)" << endl;
					esya.cinsiyet=getche();
					cout << endl;
	  
                    dosya.write((char*)&esya, sizeof(esya));
                    dosya.close();
            	  }
            	 else
                {
                    HediyelikEsya yedekesya;
                    ofstream yedekdb;
                    yedekdb.open("yedek.dat",ios::app|ios::binary);
                         
                    strcpy(yedekesya.kod,esya.kod);
          	  		strcpy(yedekesya.ad,esya.ad);
            		strcpy(yedekesya.tur,esya.tur);
            		strcpy(yedekesya.fiyat,esya.fiyat);
             		yedekesya.cinsiyet=esya.cinsiyet;
                         
             		yedekdb.write((char*)&yedekesya, sizeof(yedekesya));
                    yedekdb.close();
                }
     }
 }
    esyadboku.close();
    if(var)
    {
        if (remove("musteri.dat") == 0) 
		{
            if (rename("Yedek.dat", "musteri.dat") == 0) 
			{
                cout << "\nMüþteri baþarýyla güncellendi." << endl;
            }
        }
    }
    else
    {
               remove("yedek.dat");
               cout<<"\nKayit duzeltimedi"<<endl;                  
    }

}


