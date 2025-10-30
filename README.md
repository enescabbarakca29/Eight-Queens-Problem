# ♛ 8 Vezir Problemi (Eight Queens Problem)

Bu proje, klasik **8 Vezir Problemi**ni `C` programlama diliyle **geri izleme (backtracking)** algoritması kullanarak çözer.

## 🧩 Problem Tanımı

Amaç, 8×8’lik bir satranç tahtasına **8 veziri** öyle yerleştirmektir ki:
- Hiçbiri aynı satırda olmasın,
- Hiçbiri aynı sütunda olmasın,
- Hiçbiri aynı çaprazda (diagonal) olmasın.

Yani hiçbir vezir diğerini tehdit etmemelidir.

---

## ⚙️ Kullanılan Yöntem: Backtracking (Geri İzleme)

Algoritma, sütun sütun ilerleyerek her vezir için uygun konumları **deneme–geri dönme** (trial–error) yöntemiyle arar:

1. İlk sütuna bir vezir koy.
2. Bir sonraki sütuna geç ve uygun bir satır bul.
3. Eğer bir sütunda uygun satır bulunamazsa, geri dön (backtrack) ve önceki veziri başka satıra taşı.
4. Tüm sütunlar dolduğunda bir **çözüm** bulunmuştur.

Bu yöntem, tüm olası tahtaları denemek yerine, hatalı yerleşimleri erken eleyerek çözüm aramasını hızlandırır.

---

## 🧠 Programın Mantığı

- `board[col] = row` biçiminde bir diziyle her sütundaki vezirin satır konumu tutulur.
- `isSafe()` fonksiyonu yeni bir vezir yerleştirmeden önce satır ve çapraz çakışmalarını kontrol eder.
- `solve()` fonksiyonu recursive (özyinelemeli) biçimde çalışır ve tüm geçerli çözümleri bulur.
- `printBoard()` fonksiyonu her çözümü ekrana satranç tahtası gibi bastırır.

---

## 💻 Derleme ve Çalıştırma

### 🔸 Windows (MinGW / VS Code Terminal)
```bash
gcc eight_queens.c -o eight_queens
eight_queens
