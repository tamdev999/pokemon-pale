#ifndef GUARD_CONFIG_SPECIES_ENABLED_H
#define GUARD_CONFIG_SPECIES_ENABLED_H

// Pokémon Pale — Regional Dex Configuration
// Only families used in the Pale Regional Dex are enabled.
// All others are disabled to save ROM space.

// Generation master switches (keep TRUE — individual families control inclusion)
#define P_GEN_1_POKEMON                  TRUE
#define P_GEN_2_POKEMON                  TRUE
#define P_GEN_3_POKEMON                  TRUE
#define P_GEN_4_POKEMON                  TRUE
#define P_GEN_5_POKEMON                  TRUE
#define P_GEN_6_POKEMON                  TRUE
#define P_GEN_7_POKEMON                  TRUE
#define P_GEN_8_POKEMON                  TRUE
#define P_GEN_9_POKEMON                  TRUE

#define P_NEW_EVOS_IN_REGIONAL_DEX       TRUE

// Battle gimmick forms
#define P_MEGA_EVOLUTIONS                TRUE
#define P_PRIMAL_REVERSIONS              FALSE
#define P_ULTRA_BURST_FORMS              FALSE
#define P_GIGANTAMAX_FORMS               FALSE
#define P_TERA_FORMS                     FALSE
#define P_GEN_9_MEGA_EVOLUTIONS          P_MEGA_EVOLUTIONS

// Fusion forms
#define P_FUSION_FORMS                   FALSE

// Regional Forms
#define P_REGIONAL_FORMS                 TRUE
#define P_ALOLAN_FORMS                   TRUE
#define P_GALARIAN_FORMS                 TRUE
#define P_HISUIAN_FORMS                  TRUE
#define P_PALDEAN_FORMS                  FALSE

// Pikachu extras
#define P_PIKACHU_EXTRA_FORMS            FALSE
#define P_COSPLAY_PIKACHU_FORMS          FALSE
#define P_CAP_PIKACHU_FORMS              FALSE

// Cross-generation evolutions (needed for Annihilape, Farigiraf, Kingambit, etc.)
#define P_CROSS_GENERATION_EVOS          TRUE
#define P_GEN_2_CROSS_EVOS               P_CROSS_GENERATION_EVOS
#define P_GEN_3_CROSS_EVOS               P_CROSS_GENERATION_EVOS
#define P_GEN_4_CROSS_EVOS               P_CROSS_GENERATION_EVOS
#define P_GEN_6_CROSS_EVOS               P_CROSS_GENERATION_EVOS
#define P_GEN_8_CROSS_EVOS               P_CROSS_GENERATION_EVOS
#define P_GEN_9_CROSS_EVOS               P_CROSS_GENERATION_EVOS

// === GENERATION 1 FAMILIES ===
#define P_FAMILY_BULBASAUR               FALSE
#define P_FAMILY_CHARMANDER              FALSE
#define P_FAMILY_SQUIRTLE                FALSE
#define P_FAMILY_CATERPIE                FALSE
#define P_FAMILY_WEEDLE                  FALSE
#define P_FAMILY_PIDGEY                  FALSE
#define P_FAMILY_RATTATA                 TRUE  // Alolan Rattata/Raticate
#define P_FAMILY_SPEAROW                 FALSE
#define P_FAMILY_EKANS                   FALSE
#define P_FAMILY_PIKACHU                 TRUE  // Alolan Raichu
#define P_FAMILY_SANDSHREW               FALSE
#define P_FAMILY_NIDORAN                 FALSE
#define P_FAMILY_CLEFAIRY                TRUE  // Cleffa/Clefairy/Clefable
#define P_FAMILY_VULPIX                  TRUE  // Alolan Ninetales
#define P_FAMILY_JIGGLYPUFF              TRUE  // Igglybuff/Jigglypuff/Wigglytuff
#define P_FAMILY_ZUBAT                   FALSE
#define P_FAMILY_ODDISH                  FALSE
#define P_FAMILY_PARAS                   FALSE
#define P_FAMILY_VENONAT                 FALSE
#define P_FAMILY_DIGLETT                 FALSE
#define P_FAMILY_MEOWTH                  TRUE  // Alolan Meowth/Persian
#define P_FAMILY_PSYDUCK                 FALSE
#define P_FAMILY_MANKEY                  TRUE  // Annihilape
#define P_FAMILY_GROWLITHE               FALSE
#define P_FAMILY_POLIWAG                 FALSE
#define P_FAMILY_ABRA                    TRUE
#define P_FAMILY_MACHOP                  FALSE
#define P_FAMILY_BELLSPROUT              FALSE
#define P_FAMILY_TENTACOOL               FALSE
#define P_FAMILY_GEODUDE                 FALSE
#define P_FAMILY_PONYTA                  TRUE  // Galarian Rapidash
#define P_FAMILY_SLOWPOKE                TRUE  // Galarian Slowbro/Slowking
#define P_FAMILY_MAGNEMITE               FALSE
#define P_FAMILY_FARFETCHD               FALSE
#define P_FAMILY_DODUO                   FALSE
#define P_FAMILY_SEEL                    FALSE
#define P_FAMILY_GRIMER                  TRUE  // Alolan Muk
#define P_FAMILY_SHELLDER                FALSE
#define P_FAMILY_GASTLY                  TRUE  // STARTER
#define P_FAMILY_ONIX                    FALSE
#define P_FAMILY_DROWZEE                 TRUE
#define P_FAMILY_KRABBY                  FALSE
#define P_FAMILY_VOLTORB                 FALSE
#define P_FAMILY_EXEGGCUTE               TRUE
#define P_FAMILY_CUBONE                  TRUE  // Alolan Marowak
#define P_FAMILY_HITMONS                 FALSE
#define P_FAMILY_LICKITUNG               FALSE
#define P_FAMILY_KOFFING                 TRUE  // Galarian Weezing
#define P_FAMILY_RHYHORN                 FALSE
#define P_FAMILY_CHANSEY                 FALSE
#define P_FAMILY_TANGELA                 FALSE
#define P_FAMILY_KANGASKHAN              FALSE
#define P_FAMILY_HORSEA                  FALSE
#define P_FAMILY_GOLDEEN                 FALSE
#define P_FAMILY_STARYU                  TRUE
#define P_FAMILY_MR_MIME                 TRUE  // Galarian Mr. Mime / Mr. Rime
#define P_FAMILY_SCYTHER                 FALSE
#define P_FAMILY_JYNX                    TRUE  // Smoochum/Jynx
#define P_FAMILY_ELECTABUZZ              FALSE
#define P_FAMILY_MAGMAR                  FALSE
#define P_FAMILY_PINSIR                  FALSE
#define P_FAMILY_TAUROS                  FALSE
#define P_FAMILY_MAGIKARP                FALSE
#define P_FAMILY_LAPRAS                  FALSE
#define P_FAMILY_DITTO                   FALSE
#define P_FAMILY_EEVEE                   TRUE  // Umbreon/Sylveon/Espeon
#define P_FAMILY_PORYGON                 FALSE
#define P_FAMILY_OMANYTE                 FALSE
#define P_FAMILY_KABUTO                  FALSE
#define P_FAMILY_AERODACTYL              FALSE
#define P_FAMILY_SNORLAX                 FALSE
#define P_FAMILY_ARTICUNO                FALSE
#define P_FAMILY_ZAPDOS                  FALSE
#define P_FAMILY_MOLTRES                 FALSE
#define P_FAMILY_DRATINI                 FALSE
#define P_FAMILY_MEWTWO                  FALSE
#define P_FAMILY_MEW                     FALSE

// === GENERATION 2 FAMILIES ===
#define P_FAMILY_CHIKORITA               FALSE
#define P_FAMILY_CYNDAQUIL               TRUE  // Hisuian Typhlosion
#define P_FAMILY_TOTODILE                FALSE
#define P_FAMILY_SENTRET                 FALSE
#define P_FAMILY_HOOTHOOT                FALSE
#define P_FAMILY_LEDYBA                  FALSE
#define P_FAMILY_SPINARAK                FALSE
#define P_FAMILY_CHINCHOU                FALSE
#define P_FAMILY_TOGEPI                  TRUE  // Togekiss
#define P_FAMILY_NATU                    TRUE
#define P_FAMILY_MAREEP                  FALSE
#define P_FAMILY_MARILL                  TRUE  // Azumarill
#define P_FAMILY_SUDOWOODO               FALSE
#define P_FAMILY_HOPPIP                  FALSE
#define P_FAMILY_AIPOM                   FALSE
#define P_FAMILY_SUNKERN                 FALSE
#define P_FAMILY_YANMA                   FALSE
#define P_FAMILY_WOOPER                  FALSE
#define P_FAMILY_MURKROW                 TRUE  // Honchkrow
#define P_FAMILY_MISDREAVUS              TRUE  // Mismagius
#define P_FAMILY_UNOWN                   TRUE
#define P_FAMILY_WOBBUFFET               TRUE
#define P_FAMILY_GIRAFARIG               TRUE  // Farigiraf
#define P_FAMILY_PINECO                  FALSE
#define P_FAMILY_DUNSPARCE               FALSE
#define P_FAMILY_GLIGAR                  FALSE
#define P_FAMILY_SNUBBULL                TRUE  // Granbull
#define P_FAMILY_QWILFISH                TRUE  // Hisuian Qwilfish/Overqwil
#define P_FAMILY_SHUCKLE                 FALSE
#define P_FAMILY_HERACROSS               FALSE
#define P_FAMILY_SNEASEL                 TRUE  // Weavile
#define P_FAMILY_TEDDIURSA               FALSE
#define P_FAMILY_SLUGMA                  FALSE
#define P_FAMILY_SWINUB                  FALSE
#define P_FAMILY_CORSOLA                 TRUE  // Galarian Corsola/Cursola
#define P_FAMILY_REMORAID                FALSE
#define P_FAMILY_DELIBIRD                FALSE
#define P_FAMILY_MANTINE                 FALSE
#define P_FAMILY_SKARMORY                FALSE
#define P_FAMILY_HOUNDOUR                TRUE
#define P_FAMILY_PHANPY                  FALSE
#define P_FAMILY_STANTLER                TRUE  // Wyrdeer
#define P_FAMILY_SMEARGLE                FALSE
#define P_FAMILY_MILTANK                 FALSE
#define P_FAMILY_RAIKOU                  FALSE
#define P_FAMILY_ENTEI                   FALSE
#define P_FAMILY_SUICUNE                 FALSE
#define P_FAMILY_LARVITAR                TRUE  // Tyranitar
#define P_FAMILY_LUGIA                   FALSE
#define P_FAMILY_HO_OH                   FALSE
#define P_FAMILY_CELEBI                  FALSE

// === GENERATION 3 FAMILIES ===
#define P_FAMILY_TREECKO                 FALSE
#define P_FAMILY_TORCHIC                 FALSE
#define P_FAMILY_MUDKIP                  FALSE
#define P_FAMILY_POOCHYENA               TRUE
#define P_FAMILY_ZIGZAGOON               TRUE  // Galarian Zigzagoon/Obstagoon
#define P_FAMILY_WURMPLE                 FALSE
#define P_FAMILY_LOTAD                   FALSE
#define P_FAMILY_SEEDOT                  TRUE  // Shiftry
#define P_FAMILY_TAILLOW                 FALSE
#define P_FAMILY_WINGULL                 FALSE
#define P_FAMILY_RALTS                   TRUE  // Gardevoir/Gallade
#define P_FAMILY_SURSKIT                 FALSE
#define P_FAMILY_SHROOMISH               FALSE
#define P_FAMILY_SLAKOTH                 FALSE
#define P_FAMILY_NINCADA                 TRUE  // Shedinja
#define P_FAMILY_WHISMUR                 FALSE
#define P_FAMILY_MAKUHITA                FALSE
#define P_FAMILY_NOSEPASS                FALSE
#define P_FAMILY_SKITTY                  FALSE
#define P_FAMILY_SABLEYE                 TRUE
#define P_FAMILY_MAWILE                  TRUE
#define P_FAMILY_ARON                    FALSE
#define P_FAMILY_MEDITITE                TRUE  // Medicham
#define P_FAMILY_ELECTRIKE               FALSE
#define P_FAMILY_PLUSLE                  FALSE
#define P_FAMILY_MINUN                   FALSE
#define P_FAMILY_VOLBEAT_ILLUMISE        FALSE
#define P_FAMILY_ROSELIA                 FALSE
#define P_FAMILY_GULPIN                  FALSE
#define P_FAMILY_CARVANHA                TRUE  // Sharpedo
#define P_FAMILY_WAILMER                 FALSE
#define P_FAMILY_NUMEL                   FALSE
#define P_FAMILY_TORKOAL                 FALSE
#define P_FAMILY_SPOINK                  TRUE  // Grumpig
#define P_FAMILY_SPINDA                  FALSE
#define P_FAMILY_TRAPINCH                FALSE
#define P_FAMILY_CACNEA                  TRUE  // Cacturne
#define P_FAMILY_SWABLU                  FALSE
#define P_FAMILY_ZANGOOSE                FALSE
#define P_FAMILY_SEVIPER                 FALSE
#define P_FAMILY_LUNATONE                TRUE
#define P_FAMILY_SOLROCK                 TRUE
#define P_FAMILY_BARBOACH                FALSE
#define P_FAMILY_CORPHISH                TRUE  // Crawdaunt
#define P_FAMILY_BALTOY                  TRUE  // Claydol
#define P_FAMILY_LILEEP                  FALSE
#define P_FAMILY_ANORITH                 FALSE
#define P_FAMILY_FEEBAS                  FALSE
#define P_FAMILY_CASTFORM                FALSE
#define P_FAMILY_KECLEON                 FALSE
#define P_FAMILY_SHUPPET                 TRUE  // Banette
#define P_FAMILY_DUSKULL                 TRUE  // STARTER — Dusknoir
#define P_FAMILY_TROPIUS                 FALSE
#define P_FAMILY_CHIMECHO                TRUE  // Chingling/Chimecho
#define P_FAMILY_ABSOL                   TRUE
#define P_FAMILY_SNORUNT                 TRUE  // Froslass
#define P_FAMILY_SPHEAL                  FALSE
#define P_FAMILY_CLAMPERL                FALSE
#define P_FAMILY_RELICANTH               FALSE
#define P_FAMILY_LUVDISC                 FALSE
#define P_FAMILY_BAGON                   FALSE
#define P_FAMILY_BELDUM                  TRUE  // Metagross
#define P_FAMILY_REGIROCK                FALSE
#define P_FAMILY_REGICE                  FALSE
#define P_FAMILY_REGISTEEL               FALSE
#define P_FAMILY_LATIAS                  FALSE
#define P_FAMILY_LATIOS                  FALSE
#define P_FAMILY_KYOGRE                  FALSE
#define P_FAMILY_GROUDON                 FALSE
#define P_FAMILY_RAYQUAZA                FALSE
#define P_FAMILY_JIRACHI                 FALSE
#define P_FAMILY_DEOXYS                  FALSE

// === GENERATION 4 FAMILIES ===
#define P_FAMILY_TURTWIG                 FALSE
#define P_FAMILY_CHIMCHAR                FALSE
#define P_FAMILY_PIPLUP                  FALSE
#define P_FAMILY_STARLY                  FALSE
#define P_FAMILY_BIDOOF                  FALSE
#define P_FAMILY_KRICKETOT               FALSE
#define P_FAMILY_SHINX                   FALSE
#define P_FAMILY_CRANIDOS                FALSE
#define P_FAMILY_SHIELDON                FALSE
#define P_FAMILY_BURMY                   FALSE
#define P_FAMILY_COMBEE                  FALSE
#define P_FAMILY_PACHIRISU               FALSE
#define P_FAMILY_BUIZEL                  FALSE
#define P_FAMILY_CHERUBI                 FALSE
#define P_FAMILY_SHELLOS                 FALSE
#define P_FAMILY_DRIFLOON                TRUE  // Drifblim
#define P_FAMILY_BUNEARY                 FALSE
#define P_FAMILY_GLAMEOW                 FALSE
#define P_FAMILY_STUNKY                  TRUE  // Skuntank
#define P_FAMILY_BRONZOR                 TRUE  // Bronzong
#define P_FAMILY_CHATOT                  FALSE
#define P_FAMILY_SPIRITOMB               TRUE
#define P_FAMILY_GIBLE                   FALSE
#define P_FAMILY_RIOLU                   FALSE
#define P_FAMILY_HIPPOPOTAS              FALSE
#define P_FAMILY_SKORUPI                 TRUE  // Drapion
#define P_FAMILY_CROAGUNK                FALSE
#define P_FAMILY_CARNIVINE               FALSE
#define P_FAMILY_FINNEON                 FALSE
#define P_FAMILY_SNOVER                  FALSE
#define P_FAMILY_ROTOM                   FALSE
#define P_FAMILY_UXIE                    FALSE
#define P_FAMILY_MESPRIT                 FALSE
#define P_FAMILY_AZELF                   FALSE
#define P_FAMILY_DIALGA                  FALSE
#define P_FAMILY_PALKIA                  FALSE
#define P_FAMILY_HEATRAN                 FALSE
#define P_FAMILY_REGIGIGAS               FALSE
#define P_FAMILY_GIRATINA                FALSE
#define P_FAMILY_CRESSELIA               FALSE
#define P_FAMILY_MANAPHY                 FALSE
#define P_FAMILY_DARKRAI                 FALSE
#define P_FAMILY_SHAYMIN                 FALSE
#define P_FAMILY_ARCEUS                  FALSE

// === GENERATION 5 FAMILIES ===
#define P_FAMILY_VICTINI                 FALSE
#define P_FAMILY_SNIVY                   FALSE
#define P_FAMILY_TEPIG                   FALSE
#define P_FAMILY_OSHAWOTT                TRUE  // Hisuian Samurott
#define P_FAMILY_PATRAT                  FALSE
#define P_FAMILY_LILLIPUP                FALSE
#define P_FAMILY_PURRLOIN                TRUE  // Liepard
#define P_FAMILY_PANSAGE                 FALSE
#define P_FAMILY_PANSEAR                 FALSE
#define P_FAMILY_PANPOUR                 FALSE
#define P_FAMILY_MUNNA                   TRUE  // Musharna
#define P_FAMILY_PIDOVE                  FALSE
#define P_FAMILY_BLITZLE                 FALSE
#define P_FAMILY_ROGGENROLA              FALSE
#define P_FAMILY_WOOBAT                  FALSE
#define P_FAMILY_DRILBUR                 FALSE
#define P_FAMILY_AUDINO                  FALSE
#define P_FAMILY_TIMBURR                 FALSE
#define P_FAMILY_TYMPOLE                 FALSE
#define P_FAMILY_THROH                   FALSE
#define P_FAMILY_SAWK                    FALSE
#define P_FAMILY_SEWADDLE                FALSE
#define P_FAMILY_VENIPEDE                FALSE
#define P_FAMILY_COTTONEE                TRUE  // Whimsicott
#define P_FAMILY_PETILIL                 FALSE
#define P_FAMILY_BASCULIN                TRUE  // White-Striped/Basculegion
#define P_FAMILY_SANDILE                 TRUE  // Krookodile
#define P_FAMILY_DARUMAKA                FALSE
#define P_FAMILY_MARACTUS                FALSE
#define P_FAMILY_DWEBBLE                 FALSE
#define P_FAMILY_SCRAGGY                 TRUE  // Scrafty
#define P_FAMILY_SIGILYPH                TRUE
#define P_FAMILY_YAMASK                  TRUE  // Cofagrigus + Galarian/Runerigus
#define P_FAMILY_TIRTOUGA                FALSE
#define P_FAMILY_ARCHEN                  FALSE
#define P_FAMILY_TRUBBISH                FALSE
#define P_FAMILY_ZORUA                   TRUE  // Zoroark + Hisuian Zoroark
#define P_FAMILY_MINCCINO                FALSE
#define P_FAMILY_GOTHITA                 TRUE  // Gothitelle
#define P_FAMILY_SOLOSIS                 TRUE  // Reuniclus
#define P_FAMILY_DUCKLETT                FALSE
#define P_FAMILY_VANILLITE               FALSE
#define P_FAMILY_DEERLING                FALSE
#define P_FAMILY_EMOLGA                  FALSE
#define P_FAMILY_KARRABLAST              FALSE
#define P_FAMILY_FOONGUS                 FALSE
#define P_FAMILY_FRILLISH                TRUE  // Jellicent
#define P_FAMILY_ALOMOMOLA               FALSE
#define P_FAMILY_JOLTIK                  FALSE
#define P_FAMILY_FERROSEED               FALSE
#define P_FAMILY_KLINK                   FALSE
#define P_FAMILY_TYNAMO                  FALSE
#define P_FAMILY_ELGYEM                  TRUE  // Beheeyem
#define P_FAMILY_LITWICK                 TRUE  // STARTER — Chandelure
#define P_FAMILY_AXEW                    FALSE
#define P_FAMILY_CUBCHOO                 FALSE
#define P_FAMILY_CRYOGONAL               FALSE
#define P_FAMILY_SHELMET                 FALSE
#define P_FAMILY_STUNFISK                FALSE
#define P_FAMILY_MIENFOO                 FALSE
#define P_FAMILY_DRUDDIGON               FALSE
#define P_FAMILY_GOLETT                  TRUE  // Golurk
#define P_FAMILY_PAWNIARD                TRUE  // Bisharp/Kingambit
#define P_FAMILY_BOUFFALANT              FALSE
#define P_FAMILY_RUFFLET                 TRUE  // Hisuian Braviary
#define P_FAMILY_VULLABY                 TRUE  // Mandibuzz
#define P_FAMILY_HEATMOR                 FALSE
#define P_FAMILY_DURANT                  FALSE
#define P_FAMILY_DEINO                   TRUE  // Hydreigon
#define P_FAMILY_LARVESTA                FALSE
#define P_FAMILY_COBALION                FALSE
#define P_FAMILY_TERRAKION               FALSE
#define P_FAMILY_VIRIZION                FALSE
#define P_FAMILY_TORNADUS                FALSE
#define P_FAMILY_THUNDURUS               FALSE
#define P_FAMILY_RESHIRAM                FALSE
#define P_FAMILY_ZEKROM                  FALSE
#define P_FAMILY_LANDORUS                FALSE
#define P_FAMILY_KYUREM                  FALSE
#define P_FAMILY_KELDEO                  FALSE
#define P_FAMILY_MELOETTA                FALSE
#define P_FAMILY_GENESECT                FALSE

// === GENERATION 6 FAMILIES ===
#define P_FAMILY_CHESPIN                 FALSE
#define P_FAMILY_FENNEKIN                TRUE  // Delphox
#define P_FAMILY_FROAKIE                 TRUE  // Greninja
#define P_FAMILY_BUNNELBY                FALSE
#define P_FAMILY_FLETCHLING              FALSE
#define P_FAMILY_SCATTERBUG              FALSE
#define P_FAMILY_LITLEO                  FALSE
#define P_FAMILY_FLABEBE                 TRUE  // Eternal Flower Floette ONLY
#define P_FAMILY_SKIDDO                  FALSE
#define P_FAMILY_PANCHAM                 TRUE  // Pangoro
#define P_FAMILY_FURFROU                 FALSE
#define P_FAMILY_ESPURR                  TRUE  // Meowstic
#define P_FAMILY_HONEDGE                 TRUE  // Aegislash
#define P_FAMILY_SPRITZEE                TRUE  // Aromatisse
#define P_FAMILY_SWIRLIX                 TRUE  // Slurpuff
#define P_FAMILY_INKAY                   TRUE  // Malamar
#define P_FAMILY_BINACLE                 FALSE
#define P_FAMILY_SKRELP                  FALSE
#define P_FAMILY_CLAUNCHER               FALSE
#define P_FAMILY_HELIOPTILE              FALSE
#define P_FAMILY_TYRUNT                  FALSE
#define P_FAMILY_AMAURA                  FALSE
#define P_FAMILY_HAWLUCHA                FALSE
#define P_FAMILY_DEDENNE                 TRUE
#define P_FAMILY_CARBINK                 TRUE
#define P_FAMILY_GOOMY                   FALSE
#define P_FAMILY_KLEFKI                  TRUE
#define P_FAMILY_PHANTUMP                TRUE  // Trevenant
#define P_FAMILY_PUMPKABOO               TRUE  // Gourgeist
#define P_FAMILY_BERGMITE                FALSE
#define P_FAMILY_NOIBAT                  FALSE
#define P_FAMILY_XERNEAS                 TRUE  // STORY LEGENDARY
#define P_FAMILY_YVELTAL                 TRUE  // STORY LEGENDARY
#define P_FAMILY_ZYGARDE                 TRUE  // STORY LEGENDARY
#define P_FAMILY_DIANCIE                 FALSE
#define P_FAMILY_HOOPA                   FALSE
#define P_FAMILY_VOLCANION               FALSE

// === GENERATION 7 FAMILIES ===
#define P_FAMILY_ROWLET                  TRUE  // Decidueye
#define P_FAMILY_LITTEN                  TRUE  // Incineroar
#define P_FAMILY_POPPLIO                 TRUE  // Primarina
#define P_FAMILY_PIKIPEK                 FALSE
#define P_FAMILY_YUNGOOS                 FALSE
#define P_FAMILY_GRUBBIN                 FALSE
#define P_FAMILY_CRABRAWLER              FALSE
#define P_FAMILY_ORICORIO                TRUE  // Sensu/Pa'u styles
#define P_FAMILY_CUTIEFLY                TRUE  // Ribombee
#define P_FAMILY_ROCKRUFF                FALSE
#define P_FAMILY_WISHIWASHI              FALSE
#define P_FAMILY_MAREANIE                FALSE
#define P_FAMILY_MUDBRAY                 FALSE
#define P_FAMILY_DEWPIDER                FALSE
#define P_FAMILY_FOMANTIS                FALSE
#define P_FAMILY_MORELULL                TRUE  // Shiinotic
#define P_FAMILY_SALANDIT                FALSE
#define P_FAMILY_STUFFUL                 FALSE
#define P_FAMILY_BOUNSWEET               FALSE
#define P_FAMILY_COMFEY                  TRUE
#define P_FAMILY_ORANGURU                TRUE
#define P_FAMILY_PASSIMIAN               FALSE
#define P_FAMILY_WIMPOD                  FALSE
#define P_FAMILY_SANDYGAST               TRUE  // Palossand
#define P_FAMILY_PYUKUMUKU               FALSE
#define P_FAMILY_TYPE_NULL               FALSE
#define P_FAMILY_MINIOR                  FALSE
#define P_FAMILY_KOMALA                  FALSE
#define P_FAMILY_TURTONATOR              FALSE
#define P_FAMILY_TOGEDEMARU              FALSE
#define P_FAMILY_MIMIKYU                 TRUE
#define P_FAMILY_BRUXISH                 TRUE
#define P_FAMILY_DRAMPA                  FALSE
#define P_FAMILY_DHELMISE                TRUE
#define P_FAMILY_JANGMO_O                FALSE
#define P_FAMILY_TAPU_KOKO               FALSE
#define P_FAMILY_TAPU_LELE               FALSE
#define P_FAMILY_TAPU_BULU               FALSE
#define P_FAMILY_TAPU_FINI               FALSE
#define P_FAMILY_COSMOG                  FALSE
#define P_FAMILY_NIHILEGO                FALSE
#define P_FAMILY_BUZZWOLE                FALSE
#define P_FAMILY_PHEROMOSA               FALSE
#define P_FAMILY_XURKITREE               FALSE
#define P_FAMILY_CELESTEELA              FALSE
#define P_FAMILY_KARTANA                 FALSE
#define P_FAMILY_GUZZLORD                FALSE
#define P_FAMILY_NECROZMA                FALSE
#define P_FAMILY_MAGEARNA                FALSE
#define P_FAMILY_MARSHADOW               FALSE
#define P_FAMILY_POIPOLE                 FALSE
#define P_FAMILY_STAKATAKA               FALSE
#define P_FAMILY_BLACEPHALON             FALSE
#define P_FAMILY_ZERAORA                 FALSE
#define P_FAMILY_MELTAN                  FALSE

// === GENERATION 8 FAMILIES ===
#define P_FAMILY_GROOKEY                 FALSE
#define P_FAMILY_SCORBUNNY               FALSE
#define P_FAMILY_SOBBLE                  FALSE
#define P_FAMILY_SKWOVET                 FALSE
#define P_FAMILY_ROOKIDEE                FALSE
#define P_FAMILY_BLIPBUG                 FALSE
#define P_FAMILY_NICKIT                  TRUE  // Thievul
#define P_FAMILY_GOSSIFLEUR              FALSE
#define P_FAMILY_WOOLOO                  FALSE
#define P_FAMILY_CHEWTLE                 FALSE
#define P_FAMILY_YAMPER                  FALSE
#define P_FAMILY_ROLYCOLY                FALSE
#define P_FAMILY_APPLIN                  FALSE
#define P_FAMILY_SILICOBRA               FALSE
#define P_FAMILY_CRAMORANT               FALSE
#define P_FAMILY_ARROKUDA                FALSE
#define P_FAMILY_TOXEL                   FALSE
#define P_FAMILY_SIZZLIPEDE              FALSE
#define P_FAMILY_CLOBBOPUS               FALSE
#define P_FAMILY_SINISTEA                TRUE  // Polteageist
#define P_FAMILY_HATENNA                 TRUE  // Hatterene
#define P_FAMILY_IMPIDIMP                TRUE  // Grimmsnarl
#define P_FAMILY_MILCERY                 TRUE  // Alcremie
#define P_FAMILY_FALINKS                 FALSE
#define P_FAMILY_PINCURCHIN              FALSE
#define P_FAMILY_SNOM                    FALSE
#define P_FAMILY_STONJOURNER             FALSE
#define P_FAMILY_EISCUE                  FALSE
#define P_FAMILY_INDEEDEE                TRUE
#define P_FAMILY_MORPEKO                 TRUE
#define P_FAMILY_CUFANT                  FALSE
#define P_FAMILY_DRACOZOLT               FALSE
#define P_FAMILY_ARCTOZOLT               FALSE
#define P_FAMILY_DRACOVISH               FALSE
#define P_FAMILY_ARCTOVISH               FALSE
#define P_FAMILY_DURALUDON               FALSE
#define P_FAMILY_DREEPY                  TRUE  // Dragapult
#define P_FAMILY_ZACIAN                  FALSE
#define P_FAMILY_ZAMAZENTA               FALSE
#define P_FAMILY_ETERNATUS               FALSE
#define P_FAMILY_KUBFU                   FALSE
#define P_FAMILY_ZARUDE                  FALSE
#define P_FAMILY_REGIELEKI               FALSE
#define P_FAMILY_REGIDRAGO               FALSE
#define P_FAMILY_GLASTRIER               FALSE
#define P_FAMILY_SPECTRIER               FALSE
#define P_FAMILY_CALYREX                 FALSE
#define P_FAMILY_ENAMORUS                FALSE

// === GENERATION 9 FAMILIES ===
#define P_FAMILY_SPRIGATITO              TRUE  // Meowscarada
#define P_FAMILY_FUECOCO                 TRUE  // Skeledirge
#define P_FAMILY_QUAXLY                  FALSE
#define P_FAMILY_LECHONK                 FALSE
#define P_FAMILY_TAROUNTULA              FALSE
#define P_FAMILY_NYMBLE                  TRUE  // Lokix
#define P_FAMILY_PAWMI                   FALSE
#define P_FAMILY_TANDEMAUS               FALSE
#define P_FAMILY_FIDOUGH                 TRUE  // Dachsbun
#define P_FAMILY_SMOLIV                  FALSE
#define P_FAMILY_SQUAWKABILLY            FALSE
#define P_FAMILY_NACLI                   FALSE
#define P_FAMILY_CHARCADET               TRUE  // Ceruledge/Armarouge
#define P_FAMILY_TADBULB                 FALSE
#define P_FAMILY_WATTREL                 FALSE
#define P_FAMILY_MASCHIFF                TRUE  // Mabosstiff
#define P_FAMILY_SHROODLE                FALSE
#define P_FAMILY_BRAMBLIN                TRUE  // Brambleghast
#define P_FAMILY_TOEDSCOOL               FALSE
#define P_FAMILY_KLAWF                   FALSE
#define P_FAMILY_CAPSAKID                FALSE
#define P_FAMILY_RELLOR                  TRUE  // Rabsca
#define P_FAMILY_FLITTLE                 TRUE  // Espathra
#define P_FAMILY_TINKATINK               TRUE  // Tinkaton
#define P_FAMILY_WIGLETT                 FALSE
#define P_FAMILY_BOMBIRDIER              TRUE
#define P_FAMILY_FINIZEN                 FALSE
#define P_FAMILY_VAROOM                  FALSE
#define P_FAMILY_CYCLIZAR                FALSE
#define P_FAMILY_ORTHWORM                FALSE
#define P_FAMILY_GLIMMET                 FALSE
#define P_FAMILY_GREAVARD                TRUE  // Houndstone
#define P_FAMILY_FLAMIGO                 FALSE
#define P_FAMILY_CETODDLE                FALSE
#define P_FAMILY_VELUZA                  TRUE
#define P_FAMILY_DONDOZO                 FALSE
#define P_FAMILY_TATSUGIRI               FALSE
#define P_FAMILY_GREAT_TUSK              FALSE
#define P_FAMILY_SCREAM_TAIL             FALSE
#define P_FAMILY_BRUTE_BONNET            FALSE
#define P_FAMILY_FLUTTER_MANE            FALSE
#define P_FAMILY_SLITHER_WING            FALSE
#define P_FAMILY_SANDY_SHOCKS            FALSE
#define P_FAMILY_IRON_TREADS             FALSE
#define P_FAMILY_IRON_BUNDLE             FALSE
#define P_FAMILY_IRON_HANDS              FALSE
#define P_FAMILY_IRON_JUGULIS            FALSE
#define P_FAMILY_IRON_MOTH               FALSE
#define P_FAMILY_IRON_THORNS             FALSE
#define P_FAMILY_FRIGIBAX                FALSE
#define P_FAMILY_GIMMIGHOUL              TRUE  // Gholdengo
#define P_FAMILY_WO_CHIEN                FALSE
#define P_FAMILY_CHIEN_PAO               FALSE
#define P_FAMILY_TING_LU                 FALSE
#define P_FAMILY_CHI_YU                  FALSE
#define P_FAMILY_ROARING_MOON            FALSE
#define P_FAMILY_IRON_VALIANT            FALSE
#define P_FAMILY_KORAIDON                FALSE
#define P_FAMILY_MIRAIDON                FALSE
#define P_FAMILY_WALKING_WAKE            FALSE
#define P_FAMILY_IRON_LEAVES             FALSE
#define P_FAMILY_POLTCHAGEIST            TRUE  // Sinistcha
#define P_FAMILY_SINISTCHA               FALSE
#define P_FAMILY_OKIDOGI                 FALSE
#define P_FAMILY_MUNKIDORI               FALSE
#define P_FAMILY_FEZANDIPITI             FALSE
#define P_FAMILY_OGERPON                 FALSE
#define P_FAMILY_GOUGING_FIRE            FALSE
#define P_FAMILY_RAGING_BOLT             FALSE
#define P_FAMILY_IRON_BOULDER            FALSE
#define P_FAMILY_IRON_CROWN              FALSE
#define P_FAMILY_TERAPAGOS               FALSE
#define P_FAMILY_PECHARUNT               TRUE

#endif // GUARD_CONFIG_SPECIES_ENABLED_H
