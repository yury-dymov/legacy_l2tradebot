HEADERS       =	debug.h \
		l2bot.h \
		game_struct.h \
		b32.h \
		data.h \
		dat.h \
		catxpoint.h \
		datafunc.h \
		catx/convert.h \
		catx/parser.h \
		catx/catxfunc.h \
		catx/reader.h \
		dialog/dialog.h \
		dialog/bagdialog.h \
		dialog/tablewidget.h \
		dialog/sellbuywidget.h \
		dialog/playersellbuy.h \
		dialog/tradewidget.h \
		dialog/countdialog.h \
		dialog/npcsellbuy.h \
		dialog/npcsellbuywidget.h \
		dialog/warehouse.h \
		dialog/warehousewidget.h \
		dialog/dwarfenmanufacturewidget.h \
		dialog/dwarfenmanufacture.h \
		dialog/setmessagedialog.h \
		dialog/npchtmlmessage.h \
		dialog/trade.h \
		dialog/privatestore.h \
		dialog/playerstore.h \
		dialog/logindialog.h \
		dialog/selectserver.h \
		dialog/selectchar.h \
		dialog/vistadialog.h \
		dialog/newchar.h \
		dialog/recipeshopselllist.h \
		dialog/recipeshopiteminfo.h \
		dialog/errordialog.h \
		login/loginthread.h \
		login/classes/bfish.h \
		login/classes/serverlist.h \
		login/classes/logindata.h \
		login/packet/loginpacket.h \
		game/gamethread.h \
		game/packet/gamepacket.h \
		game/classes/gamefunc.h \
		classes/map.h  \
		classes/bag.h \
		classes/map_item.h \
		classes/map_scene.h \
		classes/info_bar.h \
		classes/chatwidget.h \
		classes/systemmessagewidget.h
SOURCES       = main.cpp \
		l2bot.cpp \
		debug.cpp \
		data.cpp \
		dat.cpp \
		catxpoint.cpp \
		datafunc.cpp \
		catx/convert.cpp \
		catx/parser.cpp \
		catx/catxfunc.cpp \
		catx/reader.cpp \
		login/loginthread.cpp \
		login/classes/serverlist.cpp \
		login/classes/bfish.cpp \
		login/classes/logindata.cpp \
		login/packet/loginpacket.cpp \
		login/packet/requestauthlogin.cpp \
		login/packet/requestserverlist.cpp \
		login/packet/requestserverlogin.cpp \
		game/gamethread.cpp \
		game/packet/gamecrypt.cpp \
		game/packet/enterworld.cpp \
		game/packet/authlogin.cpp \
		game/packet/charselected.cpp \
		game/packet/protocolversion.cpp \
		game/packet/netping.cpp \
		game/packet/requestquestlist.cpp \
		game/packet/requestmanorlist.cpp \
		game/packet/movebackwardtolocation.cpp \
		game/packet/action.cpp \
		game/packet/requestbypasstoserver.cpp \
		game/packet/requestlinkhtml.cpp \
		game/packet/validateposition.cpp \
		game/packet/requestprivatestoremanage.cpp \
		game/packet/requestprivatestorequit.cpp \
		game/packet/setprivatestorelistsell.cpp \
		game/packet/setprivatestoremsg.cpp \
		game/packet/requestprivatestoremanagebuy.cpp \
		game/packet/requestprivatestorequitbuy.cpp \
		game/packet/setprivatestorelistbuy.cpp \
		game/packet/setprivatestoremsgbuy.cpp \
		game/packet/sendprivatestorebuylist.cpp \
		game/packet/sendprivatestorebuylistbuy.cpp \
		game/packet/traderequest.cpp \
		game/packet/answertraderequest.cpp \
		game/packet/addtradeitem.cpp \
		game/packet/tradedone.cpp \
		game/packet/requestbuyitem.cpp \
		game/packet/requestsellitem.cpp \
		game/packet/sendwarehousedepositlist.cpp \
		game/packet/sendwarehousewithdrawlist.cpp \
		game/packet/requestactionuse.cpp \
		game/packet/requestrecipeshopmessageset.cpp \
		game/packet/requestrecipeshoplistset.cpp \
		game/packet/say2.cpp \
		game/packet/sendbypassbuildcmd.cpp \
		game/packet/appearing.cpp \
		game/packet/requestitemlist.cpp \
		game/packet/useitem.cpp \
		game/packet/requestrestart.cpp \
		game/packet/requestlogout.cpp \
		game/packet/requestdestroyitem.cpp \
		game/packet/requestcrystallizeitem.cpp \
		game/packet/newcharacter.cpp \
		game/packet/charcreate.cpp \
		game/packet/requestrecipeshopmakeinfo.cpp \
		game/packet/requestrecipeshopprev.cpp \
		game/packet/requestrecipeshopmakeitem.cpp \
		game/classes/privatebuylistbuy.cpp \
		game/classes/npcinfo.cpp \
		game/classes/userinfo.cpp \
		game/classes/charinfo.cpp \
		game/classes/deleteobject.cpp \
		game/classes/movetolocation.cpp \
		game/classes/movetopawn.cpp \
		game/classes/npchtmlmessage.cpp \
		game/classes/stopmove.cpp \
		game/classes/privatestoremanagelist.cpp \
		game/classes/privatestorebuymanagelist.cpp \
		game/classes/privatestorelist.cpp \
		game/classes/traderequestf.cpp \
		game/classes/tradestart.cpp \
		game/classes/tradeownadd.cpp \
		game/classes/tradeotheradd.cpp \
		game/classes/tradedonef.cpp \
		game/classes/buylist.cpp \
		game/classes/selllist.cpp \
		game/classes/warehousedepositlist.cpp \
		game/classes/privatestoremsg.cpp \
		game/classes/changewaittype.cpp \
		game/classes/recipeshopmanagelist.cpp \
		game/classes/say2f.cpp \
		game/classes/systemmessage.cpp \
		game/classes/gmhide.cpp \
		game/classes/itemlistpacket.cpp \
		game/classes/inventoryupdate.cpp \
		game/classes/teleporttolocation.cpp \
		game/classes/charselect.cpp \
		game/classes/restartresponse.cpp \
		game/classes/chartemplates.cpp \
		game/classes/charcreateok.cpp \
		game/classes/charcreatefail.cpp \
		game/classes/recipeshopselllist.cpp \
		game/classes/recipeshopiteminfo.cpp \
		classes/map.cpp \
		classes/map_item.cpp \
		classes/map_scene.cpp \
		classes/info_bar.cpp \
		classes/chatwidget.cpp \
		classes/bag.cpp \
		classes/systemmessagewidget.cpp \
		dialog/ui_npchtmlmessage.cpp \
		dialog/ui_privatestoremanagelist.cpp \
		dialog/ui_privatestoremanagebuylist.cpp \
		dialog/ui_privatestorelist.cpp \
		dialog/ui_privatestorebuylistbuy.cpp \
		dialog/ui_traderequest.cpp \
		dialog/ui_trade.cpp \
		dialog/ui_buylist.cpp \
		dialog/ui_selllist.cpp \
		dialog/ui_warehousedeposit.cpp \
		dialog/ui_warehousewithdraw.cpp \
		dialog/ui_dwarfenmanufacture.cpp \
		dialog/ui_logindialog.cpp \
		dialog/ui_selectserver.cpp \
		dialog/ui_selectchar.cpp \
		dialog/ui_recipeshopselllist.cpp \
		dialog/ui_recipeshopiteminfo.cpp \
		dialog/countdialog.cpp \
		dialog/tablewidget.cpp \
		dialog/setmessagedialog.cpp \
		dialog/tradewidget.cpp \
		dialog/sellbuywidget.cpp \
		dialog/playersellbuy.cpp \
		dialog/npcsellbuywidget.cpp \
		dialog/warehousewidget.cpp \
		dialog/dwarfenmanufacturewidget.cpp \
		dialog/bagdialog.cpp \
		dialog/vistadialog.cpp \
		dialog/newchar.cpp \
		dialog/errordialog.cpp
CONFIG += release
QT += network