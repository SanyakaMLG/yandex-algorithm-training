#include <iostream>
#include <iomanip>

int *parse_to_int(std::string str) {
    int *array = new int[3];
    array[0] = (str[0] - '0') * 10 + (str[1] - '0');
    array[1] = (str[3] - '0') * 10 + (str[4] - '0');
    array[2] = (str[6] - '0') * 10 + (str[7] - '0');
    return array;
}

int main() {
    std::string str1, str2, str3;
    getline(std::cin, str1);
    int *arr1 = parse_to_int(str1);
    getline(std::cin, str2);
    int *arr2 = parse_to_int(str2);
    getline(std::cin, str3);
    int *arr3 = parse_to_int(str3);
    int diff_h = arr3[0] - arr1[0];
    int diff_m = arr3[1] - arr1[1];
    int diff_s = arr3[2] - arr1[2];
    if (diff_h < 0) diff_h += 24;
    if (diff_m < 0) {
        diff_h--;
        diff_m += 60;
    }
    if (diff_s < 0) {
        diff_m--;
        diff_s += 60;
    }
    int diff = (diff_h * 3600 + diff_m * 60 + diff_s + 1) / 2;
    arr2[2] += diff;
    arr2[1] += arr2[2]/60;
    arr2[0] += arr2[1]/60;
    std::cout << std::setw(2) << std::setfill('0') << arr2[0]%24 << ":";
    std::cout << std::setw(2) << std::setfill('0') << arr2[1]%60 << ":";
    std::cout << std::setw(2) << std::setfill('0') << arr2[2]%60;
    return 0;
}

/*
 Для того чтобы компьютеры поддерживали актуальное время, они могут обращаться к серверам точного времени SNTP (Simple Network Time
 Protocol). К сожалению, компьютер не может просто получить время у сервера, потому что информация по сети передаётся не мгновенно:
 пока сообщение с текущим временем дойдёт до компьютера, оно потеряет свою актуальность. Протокол взаимодействия клиента (компьютера,
 запрашивающего точное время) и сервера (компьютера, выдающего точное время) выглядит следующим образом:

 1. Клиент отправляет запрос на сервер и запоминает время отправления A (по клиентскому времени).

 2. Сервер получает запрос в момент времени B (по точному серверному времени) и отправляет клиенту сообщение, содержащее время B.

 3. Клиент получает ответ на свой запрос в момент времени C (по клиентскому времени) и запоминает его.

 Теперь клиент, из предположения, что сетевые задержки при передаче сообщений от клиента серверу и от сервера клиенту одинаковы,
 может определить и установить себе точное время, используя известные значения A, B, C.
 Вам предстоит реализовать алгоритм, с точностью до секунды определяющий точное время для установки на клиенте по известным A, B и C.
 При необходимости округлите результат до целого числа секунд по правилам арифметики (в меньшую сторону, если дробная часть
 числа меньше 1/2, иначе в большую сторону).
 Возможно, что, пока клиент ожидал ответа, по клиентскому времени успели наступить новые сутки, однако известно, что между отправкой
 клиентом запроса и получением ответа от сервера прошло менее 24 часов.
 */
