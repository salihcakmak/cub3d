Keywords
- Ray Casting
- Minilibx
- Rigor
- Graphic
- 3D
- Events
- Fill Shapes
- Maze
- Floor
- Ceiling

Usefull Links
  - https://harm-smits.github.io/42docs/projects/cub3d
  - https://www.youtube.com/watch?v=gYRrGTC7GtA

Subject

minilibx kütüphanesi kullanarak ilk defa ray casting nedir nasıl yapılır öğreneceğiz.

Bu proje, şimdiye kadarki ilk FPS olan dünyaca ünlü Wolfenstein 3D oyunundan esinlenmiştir.

ray-casting 'i (Işın dökümünü) keşfetmenizi sağlayacaktır.

Amacınız, yolunuzu bulmanız gereken bir labirentin içinde dinamik bir görünüm oluşturmak olacaktır.

Chapter I (Bölüm 1)

Foreword (Önsöz)

Id Software tarafından über ünlü John Carmack ve John Romero tarafından geliştirilen, 1992 yılında Apogee Software tarafından yayınlanan Wolfenstein 3D, video oyunları tarihindeki ilk gerçek “First Person Shooter”dır.

Wolfenstein 3D ; Doom (Id Software, 1993), Doom II (Id Software, 1994), Duke Nukem 3D (3D Realm, 1996) ve Quake (Id Software, 1996) gibi oyunların atasıdır. Bunlar video oyunları dünyasında çok önemli kilometre taşlarıdır.

Şimdi, Tarihi yeniden yaşama sırası sizde.

Chapter II (Bölüm 2)

Goals (Hedefler)
- Bu projenin hedefleri, bu ilk yılın tüm hedeflerine benzer şekilde:
    - Titizlik, C kullanımı, temel algoritmaların kullanımı, bilgi araştırması vb.

- Bir grafik tasarım projesi olarak cub3D, şu alanlarda becerilerinizi geliştirmenizi sağlar:
    - pencereler, renkler, olaylar, dolgu şekilleri vb. (windows, colors, events, fill shapes, etc.)

- Sonuç olarak cub3D, ayrıntıları anlamak zorunda kalmadan matematiğin eğlenceli pratik uygulamalarını keşfetmek için dikkate değer bir oyun alanıdır.

- İnternette bulunan çok sayıda belge yardımıyla, Burada Matematiği; zarif ve verimli algoritmalar oluşturmak için bir araç olarak kullanacağız.

Bu projeye başlamadan önce orijinal oyunu test etmenizi öneririz:
http://users.atw.hu/wolf3d/

Chapter III

Common Instructions (Ortak Talimatlar)

- Projeniz C ile yazılmalıdır.
- Projeniz Norm'a uygun olarak yazılmalıdır. Bonus dosyalarınız/fonksiyonlarınız varsa, bunlar norm kontrolüne dahil edilir ve içeride bir norm hatası varsa 0 alırsınız.
- Tanımsız davranışlar dışında fonksiyonlarınız beklenmedik şekilde (segmentasyon hatası, bus hatası, double free vb.) çıkmamalıdır. Böyle bir durumda projeniz işlevsiz olarak kabul edilecek ve değerlendirme sırasında 0 alacaktır.
- Gerektiğinde, tüm heap ayrılmış bellek alanı uygun şekilde boşaltılmalıdır. Hiçbir sızıntı tolere edilmeyecektir.
- Konu gerektiriyorsa, kaynak dosyalarınızı -Wall, -Wextra ve -Werror bayraklarıyla gerekli çıktıya derleyecek bir Makefile göndermelisiniz, cc kullanın ve Makefile'niz yeniden bağlanmamalıdır.
- Makefile dosyanız en azından $(NAME), all, clean, fclean ve re kurallarını içermelidir.
- Projenize bonus vermek için, Makefile'nize, projenin ana bölümünde yasaklanmış tüm çeşitli başlıkları, kütüphaneleri veya işlevleri ekleyecek bir kural bonusu eklemelisiniz. Bonuslar farklı bir _bonus.{c/h} dosyasında olmalıdır. Mandatory ve Bonus değerlendirmesi ayrı ayrı yapılır.
- Projeniz libft'inizi kullanmanıza izin veriyorsa, kaynaklarını ve ilişkili Makefile'ı ilişkili Makefile ile bir libft klasörüne kopyalamanız gerekir. Projenizin Makefile'ı, Makefile'ı kullanarak kitaplığı derlemeli, ardından projeyi derlemelidir.
- Bu çalışmanın gönderilmesi gerekmese ve notlandırılmasa da projeniz için test programları oluşturmanızı öneririz. Size işinizi ve meslektaşlarınızın çalışmalarını kolayca test etme şansı verecektir. Bu testleri özellikle savunmanız sırasında faydalı bulacaksınız. Gerçekten de, savunma sırasında kendi testlerinizi ve/veya değerlendirdiğiniz akranınızın testlerini kullanmakta özgürsünüz.
- Çalışmanızı atanmış git deponuza gönderin. Yalnızca git deposundaki çalışmalar derecelendirilecektir. Çalışmanızı derecelendirmek için Derin Düşünce atanmışsa, akran değerlendirmelerinizden sonra yapılacaktır. Deepthink notlandırma sırasında çalışmanızın herhangi bir bölümünde bir hata olursa, değerlendirme duracaktır.

Chapter IV

Mandatory part - cub3D

Program name    -   cub3D
Turn in files   -   Tüm dosyaların
Makefile        -   all, clean, fclean, re, bonus
Arguments       -   *.cup uzantı formatlı bir harita
External Func   -   open close write read printf, malloc, free, perror, strerror, exit.
                    All functions of the math library (-lm man man 3 math).
                    All functions of the MinilibX
Libft auth      -   Evet
Description     -   (first-person perspective)Birinci şahıs bakış açısıyla bir labirentin içinin "realistic" bir 3B grafik temsilini oluşturmalısınız. Bu gösterimi daha önce bahsedilen "Ray-Casting" ilkelerini kullanarak oluşturmalısınız.

Kısıtlamalar aşağıdaki gibidir:
    - MiniLibX'i kullanmalısınız. Ya işletim sisteminde bulunan ya da kaynaklarından gelen sürümü. Kaynaklarla çalışmayı seçerseniz, libft'iniz için yukarıda Ortak Yönergeler bölümünde yazılanlarla aynı kuralları uygulamanız gerekecektir.
    - Pencerenizin yönetimi sorunsuz kalmalıdır: başka bir pencereye geçme, simge durumuna küçültme vb.
    - duvarın hangi tarafa baktığına bağlı olarak (Kuzey Güney Doğu Batı) değişen farklı duvar dokuları (seçim sizin) görüntüleyin.
    - Programınız zemin ve tavan renklerini iki farklı renge ayarlayabilmelidir.
    - Program görüntüyü bir pencerede görüntüler ve aşağıdaki kurallara uyar:
        - Klavyenin sol ve sağ ok tuşları labirentte sağa ve sola bakmanıza izin vermelidir.
        - W, A, S ve D tuşları, bakış açısını labirentte hareket ettirmenize izin vermelidir.
        - ESC'ye basmak pencereyi kapatmalı ve programdan temiz bir şekilde çıkmalıdır.
        - Pencere çerçevesindeki kırmızı çarpı işaretine tıklamak pencereyi kapatmalı ve programdan temiz bir şekilde çıkmalıdır.
        - MinilibX görüntülerinin(images) kullanılması şiddetle tavsiye edilir.
    - Programınız ilk argüman olarak ".cub" uzantılı bir sahne açıklama dosyası almalıdır.
        - Harita sadece 6 olası karakterden oluşmalıdır : Boş alan için 0, duvar için 1, ve oyuncunun başlangıç pozisyonu ve (spawning orientation) yumurtlama oryantasyonu için N,G,D veya W olabilir.
        - Bu basit bir geçerli harita:
            111111
            100101
            101001
            1100N1
            111111
        - Harita kapalı/duvarlarla çevrili olmalı, değilse program bir hata vermelidir.
        - Harita içeriği dışında, her öğe türü bir veya daha fazla boş satırla ayrılabilir.
        - Her zaman en son olması gereken harita içeriği dışında, her öğe türü dosyada herhangi bir sırada ayarlanabilir.
        - Harita dışında, bir öğeden gelen her bilgi türü bir veya daha fazla boşlukla ayrılabilir.
        - Harita, dosyada göründüğü gibi ayrıştırılmalıdır. Boşluklar haritanın geçerli bir parçasıdır ve işlemek size kalmıştır. Harita kurallarına uyduğu sürece her tür haritayı ayrıştırabilmeniz gerekir.
        - Her öğenin (harita hariç) ilk bilgileri, tür tanımlayıcısıdır (bir veya iki karakterden oluşur), ardından her nesne için kesin bir sırayla tüm özel bilgiler gelir.
        Örneğin:
            * North texture	(Kuzey Dokusu)	:
              - NO ./path_to_the_north_texture
              - Tanımlayıcısı : NO
              - North texure klasör yolu

            * South texture	(Güney Dokusu)	:
              - SO ./path_to_the_south_texture
              - Tanımlayıcısı : SO
              - South texure klasör yolu

            * West texture	(Batı Dokusu)	:
              - WE ./path_to_the_west_texture
              - Tanımlayıcısı : WE
              - West texure klasör yolu

            * East texture	(Doğu Dokusu)	:
              - EA ./path_to_the_east_texture
              - Tanımlayıcısı : EA
              - East texture klasör yolu

            * Floor Color	(Zemin Rengi)	:
              - F 220,100,0
              - Tanımlayıcısı : F
              - R, G, B renk aralığı [0, 255]: 0, 255, 255

            * Ceilling Color (Tavan Rengi)	:
              - C 225,30,0
              - Tanımlayıcısı : C
              - R, G, B renk aralığı [0, 255]: 0, 255, 255

		- Minimalist bir .cub faliyet alanına sahip zorunlu kısım örneği:
		
					NO ./path_to_the_north_texture
					SO ./path_to_the_south_texture
					WE ./path_to_the_west_texture
					EA ./path_to_the_east_texture

					F 220,100,0
					C 225,30,0

                  1111111111111111111111111
                  1000000000110000000000001
                  1011000001110000000000001
                  1001000000000000000000001
					111111111011000001110000000000001
					100000000011000001110111111111111
					11110111111111011100000010001
					11110111111111011101010010001
					11000000110101011100000010001
					10000000000000001100000010001
					10000000000000001101010010001
					11000001110101011111011110N0111
					11110111 1110101 101111010001
					11111111 1111111 111111111111
		
		- Dosyada herhangi bir yanlış yapılandırmayla karşılaşılırsa program düzgün bir şekilde çıkmalıdır. "Error\n" yazmalıdır. Ardından seçtiğiniz açık bir hata mesajı döndürmelidir.