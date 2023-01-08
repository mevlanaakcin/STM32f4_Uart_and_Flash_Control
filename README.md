# STM32f4_Uart_and_Flash_Control
STM32F4 UART ile Led ve Flash Memory Kontrol Uygulaması

STM32F411RE NUCLEO Board üzerinde UART arayüzü ile  led, Flash Hafıza kontrolü sağlanmıştır.<br><br>

Echo ile Uarttan veri alınabilir.<br>
Echo ile Led açık kalma süresi ve kapalı kalma süresi ayarlanabilir.<br>
Açık kalma ve kapalı kalma süreleri flash hafızaya yazılarak enerji kesilip tekrar verildiğinde son girilen değerler tekrar kullanılabilir.<br><br>

Echo'yu pasif etmek için ;<br>
```
<h3>stop</h3>
```
Echo'yu aktif etmek için ;<br>
```
<h3>start</h3>
```

Led açık kalma süresini ayarlamak için ;<br>
```
<h3>ledon=TIME_MS</h3>
```

Led kapalı kalma süresini ayarlamak için ;<br>
```
<h3>ledoff=TIME_MS</h3>
```

## Test Etmek
STM32F4RE Nucleo kartında kullanmak için .rar olarak paylaşılan dosyayı kullanabilirsiniz.
