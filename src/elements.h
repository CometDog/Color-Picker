static Window *s_main_window;
static TextLayer *s_color_text_1, *s_color_text_2, *s_color_text_3;
static Layer *s_color_layer_1, *s_color_layer_2, *s_color_layer_3;

static int layernum = 0;
static int color1 = 0;
static int color2 = 1;
static int color3 = 2;

static const char *colorname[] = {"Black", "Oxford Blue", "Bulgarian Rose", "Imperial Purple",
"Dark Candy Apple Red", "Jazzberry Jam", "Red", "Folly", "Duke Blue", "Blue", "Indigo", "Electric Ultramarine",
"Purple", "Vivid Violet", "Fashion Magenta", "Magenta", "Dark Green", "Midnight Green", "Army Green", 
"Dark Grey", "Windsor Tan", "Rose Vale", "Orange", "Sunset Orange", "Cobalt Blue", "Blue Moon", "Liberty",
"Very Light Blue", "Purpureus", "Lavender Indigo", "Brilliant Rose", "Shocking Pink",
"Islamic Green", "Jaeger Green", "Kelly Green", "May Green", "Limerick", "Brass", "Chrome Yellow",
"Rajah", "Tiffany Blue", "Vivid Cerulean", "Cadet Blue", "Picton Blue", "Light Grey", "Baby Blue Eyes", 
"Melon", "Rich Brilliant Lavender", "Green", "Malachite", "Bright Green", "Screamin' Green", "Spring Bud",
"Inchworm", "Yellow", "Icterine", "Medium Spring Green", "Cyan", "Medium Aquamarine", "Electric Blue", "Mint Green",
"Celeste", "Pastel Yellow", "White"};

static uint8_t gcolor[] = {GColorBlackARGB8, GColorOxfordBlueARGB8, GColorBulgarianRoseARGB8, GColorImperialPurpleARGB8,
GColorDarkCandyAppleRedARGB8, GColorJazzberryJamARGB8, GColorRedARGB8, GColorFollyARGB8, GColorDukeBlueARGB8, GColorBlueARGB8,
GColorIndigoARGB8, GColorElectricUltramarineARGB8, GColorPurpleARGB8, GColorVividVioletARGB8, GColorFashionMagentaARGB8, GColorMagentaARGB8,
GColorDarkGreenARGB8, GColorMidnightGreenARGB8, GColorArmyGreenARGB8, GColorDarkGrayARGB8, GColorWindsorTanARGB8, GColorRoseValeARGB8,
GColorOrangeARGB8, GColorSunsetOrangeARGB8, GColorCobaltBlueARGB8, GColorBlueMoonARGB8, GColorLibertyARGB8, GColorVeryLightBlueARGB8,
GColorPurpureusARGB8, GColorLavenderIndigoARGB8, GColorBrilliantRoseARGB8, GColorShockingPinkARGB8, GColorIslamicGreenARGB8,
GColorJaegerGreenARGB8, GColorKellyGreenARGB8, GColorMayGreenARGB8, GColorLimerickARGB8, GColorBrassARGB8, GColorChromeYellowARGB8,
GColorRajahARGB8, GColorTiffanyBlueARGB8, GColorVividCeruleanARGB8, GColorCadetBlueARGB8, GColorPictonBlueARGB8, GColorLightGrayARGB8,
GColorBabyBlueEyesARGB8, GColorMelonARGB8, GColorRichBrilliantLavenderARGB8, GColorGreenARGB8, GColorMalachiteARGB8, GColorBrightGreenARGB8,
GColorScreaminGreenARGB8, GColorSpringBudARGB8, GColorInchwormARGB8, GColorYellowARGB8, GColorIcterineARGB8, GColorMediumSpringGreenARGB8,
GColorCyanARGB8, GColorMediumAquamarineARGB8, GColorElectricBlueARGB8, GColorMintGreenARGB8, GColorCelesteARGB8, GColorPastelYellowARGB8,
GColorWhiteARGB8};