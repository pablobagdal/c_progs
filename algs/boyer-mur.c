
// - начинаем с предпоследнего справа налево и считаем расстояние до последнего символа
// - если символ уже встречался, то пишем наименьшее расстояние
// - когда дошли до начала образа, то последнему символу в соответсвие поставим:
// --если символ в строке встречался, то это же расстояние(как наименьшее)
// --иначе длина всего образа(на один больше, чем у первого символа)
// - вводим звёздочка(расстояние для символов, которых нет в образе) 
// // 2

// - сопоставляем образ и строку(выравниваем по левой границе)
// - сравниваем последний символ образа с символом из строки, имеющим соответвующий индекс
// - если совпали, то начинаем сравнивать предшествующие символы строки и образа (цикл)
// - если прошли весь образ - конец - выводим индекс, соответствующий началу образа
// - если не совпали, то
// -- если это первое сравнение в данной позиции, то сдвигаем образ вправо на значение из таблицы, соответствующее символу строки
// -- если это не первое сравнение в данной позиции, то сдвигаем образ вправо на значение из таблицы, соответствующее последнему символу из образа


#include <string.h>
#include <limits.h>

/* Вход: needle+nlen - что искать
 *   offset - позиция конца суффикса; suffixlen - его длина
 * Выход: 1, если есть совпадение суффикса (и нет совпадения более длинного суффикса)
 */
static int suffix_match(const unsigned char *needle, size_t nlen, size_t offset, size_t suffixlen)
{
    if (offset > suffixlen)
        return needle[offset - suffixlen - 1] != needle[nlen - suffixlen - 1] &&
            memcmp(needle + nlen - suffixlen, needle + offset - suffixlen, suffixlen) == 0;
    else
        return memcmp(needle + nlen - offset, needle, offset) == 0;
}

static size_t max(size_t a, size_t b)
{
    return a > b ? a : b; 
}

/* Вход: haystack - где искать, needle - что искать.
 *   hlen - длина haystack, nlen - длина needle
 * Выход: указатель на первое вхождение needle в haystack, либо NULL
 */
const unsigned char* memmem_boyermoore
    (const unsigned char* haystack, size_t hlen,
     const unsigned char* needle,   size_t nlen)
{
    size_t skip[nlen];          /* Таблица суффиксов */
    size_t occ[UCHAR_MAX + 1]; /* Таблица стоп-символов */
    
    if(nlen > hlen || nlen <= 0 || !haystack || !needle) 
        return NULL;

    /* ПОСТРОЕНИЕ ТАБЛИЦЫ СТОП-СИМВОЛОВ */
    
    /* Заполняем -1 (в Си нумерация символов с 0!!) */
    for(size_t a=0; a<UCHAR_MAX+1; ++a)
        occ[a] = -1;
    
    /* В таблицу occ записывается последнее вхождение в needle  */
    /* (исключая последний символ) */
    for(size_t a = 0; a < nlen - 1; ++a) 
        occ[needle[a]] = a;
    
    /* ПОСТРОЕНИЕ ТАБЛИЦЫ СУФФИКСОВ */  
    /* Упрощённый вариант. Можно реализовать быстрее. */
    for(size_t a = 0; a < nlen; ++a)
    {
        size_t offs = nlen;
        while(offs && !suffix_match(needle, nlen, offs, a))
            --offs;
        skip[nlen - a - 1] = nlen - offs;
    }
    
    /* ПОИСК */
    for(size_t hpos = 0; hpos <= hlen - nlen; )
    {
        size_t npos = nlen - 1;
        /* Сверка needle и haystack с конца */
        while(needle[npos] == haystack[npos + hpos])
        {
            if(npos == 0) 
                return haystack + hpos;

            --npos;
        }
        /* Не совпало! */
        hpos += max(skip[npos], npos - occ[haystack[npos + hpos]]);
        /*          ^^^         ^^^^                               */
        /*        суффикс     стоп-символ                          */
    }
    return NULL;
}