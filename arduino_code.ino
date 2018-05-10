//## Ogrenci: Muhammet Ali Akat
//## Danışman: Gökhan ATALI
//## https://www.youtube.com/channel/UCTFbvj1FfS6lOjwG22bsHfg

#include<Servo.h>
 
Servo  beta;
Servo omega;
Servo anka;
Servo wolf;  // SERVO MOTORLARIMIZI BELİRLEDİK

const int omuz=A0;    
const int kanca=A1;       
const int dirsek=A2;  
const int omurga=A3;  // potansiyometre den okumamız gereken  analog girişlerini girdik .


int x_alfa;
int y_kanca;
int x_dirsek;
int y_omurga;    // potansiyometre analog girişler için degişkenler giridik.

const int sag1=12;
 const int sag2=11;
const int sol1=10;
const int sol2=9;  // sürücü kartımızın motor çıkışlarını tanımladık .

char alfa; //bluetooth tan gelen bilgi cahar ile yani karakter olarak okuması için tanımlayacagımız degişken .



void setup() {
Serial.begin(9600);  // haberleşme hızımızı girdik.

beta.attach(2);
omega.attach(4);
anka.attach(3);
wolf.attach(5);   // servo motorlarımızın bilgi uçlarını tanımladık.

////////////////////
pinMode(sag1,OUTPUT);
pinMode(sag2,OUTPUT); 
pinMode(sol1,OUTPUT);
pinMode(sol2,OUTPUT); // sürücü motorlarımızın çıkışlarını tanımladık .
}

void loop()
{
   x_alfa =analogRead(omuz);  //x_alfa degişkenini potansiyometre den gelen veriyi okuttuk.
x_alfa=map(x_alfa,0,1023,5,80);// x_alfa degişkenini map komutuyla okudugu degerler aralıgını degiştirdik .
beta.write(x_alfa); //Servo motorun çalışması için istenilen konuma okudugu deger kadar hareket etmesini sagladık.
delay(15); // servo motorun hareketini 15 milisniye aralıklarında hareketini sagladık.

y_kanca =analogRead(kanca); //y_kanca degişkenini potansiyometre den gelen veriyi okuttuk.
y_kanca=map(y_kanca,0,1023,120,182);// y_kanca degişkenini map komutuyla okudugu degerler aralıgını degiştirdik .
omega.write(y_kanca); //Servo motorun çalışması için istenilen konuma okudugu deger kadar hareket etmesini sagladık
delay(15); // servo motorun hareketini 15 milisniye aralıklarında hareketini sagladık.

x_dirsek=analogRead(dirsek); //x_dirsek degişkenini potansiyometre den gelen veriyi okuttuk.
x_dirsek=map(x_dirsek,0,1023,5,95);// x_dirsek degişkenini map komutuyla okudugu degerler aralıgını degiştirdik .
anka.write(x_dirsek);//Servo motorun çalışması için istenilen konuma okudugu deger kadar hareket etmesini sagladık
delay(15); // servo motorun hareketini 15 milisniye aralıklarında hareketini sagladık.

y_omurga=analogRead(omurga);//y_omurga degişkenini potansiyometre den gelen veriyi okuttuk.
y_omurga=map(y_omurga,0,1023,3,178);// y_omurga degişkenini map komutuyla okudugu degerler aralıgını degiştirdik .
wolf.write(y_omurga);//Servo motorun çalışması için istenilen konuma okudugu deger kadar hareket etmesini sagladık
delay(15);  // servo motorun hareketini 15 milisniye aralıklarında hareketini sagladık.

  if(Serial.available()>0) // bu komutta gelen verileri ascii karekterlerinin degerlerini okurken 0 dan küçük degerler gelirse okuma olarak tanımladık .
{
  alfa=Serial.read(); //burda seri haberleşmede bluetoot tan gelen verileri alfa degişkenin içine kaydediyoruz.
} 

if(alfa=='G') // eger bluetoot tan gelen veri G ise motorlar geri yönde çalışmaktadır.
{
  digitalWrite(sag1,1);
  digitalWrite(sag2,0);
  digitalWrite(sol1,1);
  digitalWrite(sol2,0);
  Serial.println("geri");
}
if(alfa=='I')// eger bluetoot tan gelen veri I ise motorlar ileri yönde hareket etmektedir.
{
  digitalWrite(sag1,0);
  digitalWrite(sag2,1);
  digitalWrite(sol1,0);
  digitalWrite(sol2,1); 
  Serial.println("ileri");
}
if(alfa=='R')  // eger bluetoottan gelen veri R ise araç sağa dogru hareket etmektedir.
{
  digitalWrite(sag1,1);
  digitalWrite(sag2,0);
  digitalWrite(sol1,0);
  digitalWrite(sol2,1); 
  Serial.println("saga");
} 
if(alfa=='L')   // eger bluetoottan gelen veri L ise motorlar sola dogru hareket etmektedir.
{
  digitalWrite(sag1,0);
  digitalWrite(sag2,1);
  digitalWrite(sol1,1);
  digitalWrite(sol2,0); 
  Serial.println("sola");
}
if(alfa=='S')  // eger bluetoot tan gelen veri S ise motorlar duruyor.
{
  digitalWrite(sag1,0);
  digitalWrite(sag2,0);
  digitalWrite(sol1,0);
  digitalWrite(sol2,0); 
  Serial.println("stop");
}


Serial.print("omuz= ");
Serial.println(x_alfa);
Serial.print("kanca= ");
Serial.println(y_kanca);
Serial.print("dirsek=");    // burada genel anlamda tanımladıgımız degişkenlerden veriler yani potansiyometre den gelen verileri okuyarak her bir okunan deger ekranda görünmektedir.
Serial.println(x_dirsek);
Serial.print("omurga= ");
Serial.println(y_omurga);
Serial.println("/////////////////");
} 


