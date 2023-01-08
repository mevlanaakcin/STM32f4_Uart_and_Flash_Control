# STM32f4_Uart_and_Flash_Control
STM32F4 UART ile Led ve Flash Memory Kontrol Uygulaması

STM32F411RE NUCLEO Board üzerinde UART arayüzü ile  led, Flash Hafıza kontrolü sağlanmıştır.<br><br>

Echo ile Uarttan veri alınabilir.<br>
Echo ile Led Açık/Kapalı kalma süresi ayarlanabilir.<br>
Açık kalma ve kapalı kalma süreleri flash hafızaya yazılarak enerji kesilip tekrar verildiğinde son girilen değerler tekrar kullanılabilir.<br><br>

Echo'yu pasif etmek için ;<br>
```
stop
```
Echo'yu aktif etmek için ;<br>
```
start
```

Led açık kalma süresini ayarlamak için ;<br>
```
ledon=TIME_MS
```

Led kapalı kalma süresini ayarlamak için ;<br>
```
ledoff=TIME_MS
```

## Test Etmek
STM32F4RE Nucleo kartında kullanmak için .rar olarak paylaşılan dosyayı kullanabilirsiniz.<br>
Uart arayüzüne veri Göndermek/Almak için  RealTerm vb. programlar kullanılabilir. Ben Arduino IDE de yer alan Serial Mönitörü kullandım.
