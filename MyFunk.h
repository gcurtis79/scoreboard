
//#include <ArduinoOTA.h>
//#include <ESP8266WiFi.h>
//#include <ESP8266mDNS.h>

//void dd(int line, char* a, char* n = "") {
//  line = line * 8;
//  char text[50];
//  char spaces[30] = "                             ";
//  sprintf(text, "%s%s", a, n);
//  int end = strlen(text);
//  strcat(text, &spaces[end]);
//
//  Serial.println(text);
//  //Serial.println(text);
//}
//
//char* ip2CharArray(IPAddress ip) {
//  static char a[16];
//  sprintf(a, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
//  return a;
//}
//
//// WiFi AP Array
//// Each line is { "SSID", "PASSWORD" },
//// Last line has no trailing comma (,)
//char * wifi[][2] = {
//  { "Loading...", "pr0sper0" },
//  { "QC Co-Lab", "hackerspace" },
//  { "HomeNet", "pito10digits" }
//};
//// Increase this if you add networks
//int numNets = 3;
//
//// Scans available networks
//// Checks each AP in the wifi[][] array
//// Connects to the first one it finds available
//void scanConnect() {
//  Serial.println("WiFi Init");
//  int n = WiFi.scanNetworks();
//  for (int i = 0; i < numNets; ++i) {
//    for (int o = 0; o < n; ++o) {
//      if (WiFi.SSID(o) == wifi[i][0] ) {
//        WiFi.mode(WIFI_STA);
//        WiFi.begin(wifi[i][0], wifi[i][1]);
//        while (WiFi.status() != WL_CONNECTED) {
//          delay(100);
//        }
//        return;
//      }
//    }
//  }
//}
