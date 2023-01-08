# STM32f4_Uart_and_Flash_Control
STM32F4 UART ile Led ve Flash Memory Kontrol Uygulaması

STM32F411RE NUCLEO Board üzerinde UART arayüzü ile  led, Flash Hafıza kontrolü sağlanmıştır.

Echo ile Uarttan veri alınabilir.
Echo ile Led açık kalma süresi ve kapalı kalma süresi ayarlanabilir.
Açık kalma ve kapalı kalma süreleri flash hafızaya yazılarak enerji kesilip tekrar verildiğinde son girilen değerler tekrar kullanılabilir.

Echo'yu pasif etmek için ;
'''

stop

'''