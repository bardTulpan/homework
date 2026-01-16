def main():
    n = int(input())
    
    slovar = {}
    
    for i in range(n):
        stroka = input().strip()
        parts = stroka.split(' - ')
        eng_word = parts[0]
        lat_words = parts[1].split(', ')
        
        for lat in lat_words:
            lat_clean = lat.strip()
            if lat_clean not in slovar:
                slovar[lat_clean] = []
            slovar[lat_clean].append(eng_word)
    
    sort_lat = sorted(slovar.keys())
    
    print(len(sort_lat))
    
    for lat_word in sort_lat:
        eng_list = sorted(slovar[lat_word])
        result = ', '.join(eng_list)
        print(f"{lat_word} - {result}")

if __name__ == "__main__":
    main()