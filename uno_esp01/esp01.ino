#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//Koneksi ke mesin
cost char *ssid = "GConnect";
cost char *password = "12345678";
//===================================

/* 
// pengaturan batasan user
IPAddress IP(192,168,0,2);
IPAddress NETMASK(255,255,255,192);
IPAddress NETWORK(192,168,0,1);
IPAddress DNS(192,168,0,1);
*/

ESP8266WebServer server(80); //port web

String halaman;

void setup(){
    Serial.begin(9600);
    delay(10);
    
    Serial.print(" Sambungan ke : ");
    Serial.println(ssid);
    
    WiFi.begin(ssid,password);
    //WiFi.config(IP, NETWORK, NETMASK, DNS); // jika batasan USER dipakai
    
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    Serial.print("\n");
    Serial.print("Alamat Internet : ");
    Serial.prnt(Wifi.localIP());
    Serial.print("\n");
    Serial.print("Konek ke : ");
    Serial.println(ssid);


    //tampil index web
    halaman += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    halaman += "<center><h1>Gconnect</h1></center>";
    halaman += "<br></br>";
    halaman += "<style> .button1 {width:250px; background-color: #0000ff; Heigh:} .button2 {background-color: #CD5C5C;}";
    halaman += ".button {border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; marrgin: 2px; cursor: pointer;}</style>";
    halaman += "<center><a href=\"nyala\"\"><button class='button button1'>Nyala</button></a>";
    halaman += "<a href=\"mati\"\"><button class='button button1'>mati</button></a><br></br></center>";
    halaman += "</head>";

    //fungsi js
    server.on("/", []() {
        server.send(200, "text/html", halaman);
    });

    //fungsi js ke serial 
    server.on("/nyala", []() {
        server.send(200,"text/html", halaman);
        Serial.write(1); // urutan
        delay(1000);//satuan milidetik 1000 sama dengan 1 detik
    });

    server.on("/mati", []() {
        server.send(200,"text/html", halaman);
        Serial.write(2); // urutan
        delay(1000);//satuan milidetik 1000 sama dengan 1 detik
    })

    server.begin();
    Serial.println("Siap Di Oprasikan...");
}

void loop(){
    server.handleClient();
}
