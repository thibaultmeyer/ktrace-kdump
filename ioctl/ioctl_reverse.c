#include "ioctl_reverse.h"

const char*	get_ioctl_define_name(u_long value)
{
#if defined (FBIOMONINFO)
if (value == FBIOMONINFO)
	return ("FBIOMONINFO");
#endif
 #if defined (FIOASYNC)
if (value == FIOASYNC)
	return ("FIOASYNC");
#endif
 #if defined (TIOCCONS)
if (value == TIOCCONS)
	return ("TIOCCONS");
#endif
 #if defined (PPS_IOC_SETPARAMS)
if (value == PPS_IOC_SETPARAMS)
	return ("PPS_IOC_SETPARAMS");
#endif
 #if defined (FBIO_ADAPTER)
if (value == FBIO_ADAPTER)
	return ("FBIO_ADAPTER");
#endif
 #if defined (MTIOCHLOCATE)
if (value == MTIOCHLOCATE)
	return ("MTIOCHLOCATE");
#endif
 #if defined (CDIOCPITCH)
if (value == CDIOCPITCH)
	return ("CDIOCPITCH");
#endif
 #if defined (FBIOGATTR)
if (value == FBIOGATTR)
	return ("FBIOGATTR");
#endif
 #if defined (FBIO_GETLINEWIDTH)
if (value == FBIO_GETLINEWIDTH)
	return ("FBIO_GETLINEWIDTH");
#endif
 #if defined (KDGKBINFO)
if (value == KDGKBINFO)
	return ("KDGKBINFO");
#endif
 #if defined (FBIO_SETDISPSTART)
if (value == FBIO_SETDISPSTART)
	return ("FBIO_SETDISPSTART");
#endif
 #if defined (CDRIOCINITWRITER)
if (value == CDRIOCINITWRITER)
	return ("CDRIOCINITWRITER");
#endif
 #if defined (TIOCSETA)
if (value == TIOCSETA)
	return ("TIOCSETA");
#endif
 #if defined (TIOCSETC)
if (value == TIOCSETC)
	return ("TIOCSETC");
#endif
 #if defined (FIODTYPE)
if (value == FIODTYPE)
	return ("FIODTYPE");
#endif
 #if defined (TIOCSETD)
if (value == TIOCSETD)
	return ("TIOCSETD");
#endif
 #if defined (TIIOCSETTRACE)
if (value == TIIOCSETTRACE)
	return ("TIIOCSETTRACE");
#endif
 #if defined (VT_GETACTIVE)
if (value == VT_GETACTIVE)
	return ("VT_GETACTIVE");
#endif
 #if defined (define)
if (value == define)
	return ("define");
#endif
 #if defined (MTIOCRDHPOS)
if (value == MTIOCRDHPOS)
	return ("MTIOCRDHPOS");
#endif
 #if defined (FBIO_GETMODE)
if (value == FBIO_GETMODE)
	return ("FBIO_GETMODE");
#endif
 #if defined (TIOCTIMESTAMP)
if (value == TIOCTIMESTAMP)
	return ("TIOCTIMESTAMP");
#endif
 #if defined (CHIOEXCHANGE)
if (value == CHIOEXCHANGE)
	return ("CHIOEXCHANGE");
#endif
 #if defined (KDGETREPEAT)
if (value == KDGETREPEAT)
	return ("KDGETREPEAT");
#endif
 #if defined (FBIOGXINFO)
if (value == FBIOGXINFO)
	return ("FBIOGXINFO");
#endif
 #if defined (TIOCGWINSZ)
if (value == TIOCGWINSZ)
	return ("TIOCGWINSZ");
#endif
 #if defined (TIOCSETN)
if (value == TIOCSETN)
	return ("TIOCSETN");
#endif
 #if defined (CHIOSPICKER)
if (value == CHIOSPICKER)
	return ("CHIOSPICKER");
#endif
 #if defined (TIOCSETP)
if (value == TIOCSETP)
	return ("TIOCSETP");
#endif
 #if defined (FBIOSCURSOR)
if (value == FBIOSCURSOR)
	return ("FBIOSCURSOR");
#endif
 #if defined (FIOSETOWN)
if (value == FIOSETOWN)
	return ("FIOSETOWN");
#endif
 #if defined (TIIOCGETPARAMS)
if (value == TIIOCGETPARAMS)
	return ("TIIOCGETPARAMS");
#endif
 #if defined (CDIOCCAPABILITY)
if (value == CDIOCCAPABILITY)
	return ("CDIOCCAPABILITY");
#endif
 #if defined (VT_GETINDEX)
if (value == VT_GETINDEX)
	return ("VT_GETINDEX");
#endif
 #if defined (CONS_GET)
if (value == CONS_GET)
	return ("CONS_GET");
#endif
 #if defined (CONS_SETTERM)
if (value == CONS_SETTERM)
	return ("CONS_SETTERM");
#endif
 #if defined (TIOCSWINSZ)
if (value == TIOCSWINSZ)
	return ("TIOCSWINSZ");
#endif
 #if defined (FBIO_GETPALETTE)
if (value == FBIO_GETPALETTE)
	return ("FBIO_GETPALETTE");
#endif
 #if defined (TIOCOUTQ)
if (value == TIOCOUTQ)
	return ("TIOCOUTQ");
#endif
 #if defined (CONS_HISTORY)
if (value == CONS_HISTORY)
	return ("CONS_HISTORY");
#endif
 #if defined (TIOCMBIC)
if (value == TIOCMBIC)
	return ("TIOCMBIC");
#endif
 #if defined (CDIOCPLAYMSF)
if (value == CDIOCPLAYMSF)
	return ("CDIOCPLAYMSF");
#endif
 #if defined (CONS_GETVERS)
if (value == CONS_GETVERS)
	return ("CONS_GETVERS");
#endif
 #if defined (CHIOGPICKER)
if (value == CHIOGPICKER)
	return ("CHIOGPICKER");
#endif
 #if defined (MOUSE_SETRESOLUTION)
if (value == MOUSE_SETRESOLUTION)
	return ("MOUSE_SETRESOLUTION");
#endif
 #if defined (TIOCGLTC)
if (value == TIOCGLTC)
	return ("TIOCGLTC");
#endif
 #if defined (TIOCSETAF)
if (value == TIOCSETAF)
	return ("TIOCSETAF");
#endif
 #if defined (CHIOSETVOLTAG)
if (value == CHIOSETVOLTAG)
	return ("CHIOSETVOLTAG");
#endif
 #if defined (TIOCLBIC)
if (value == TIOCLBIC)
	return ("TIOCLBIC");
#endif
 #if defined (FBIOGCURMAX)
if (value == FBIOGCURMAX)
	return ("FBIOGCURMAX");
#endif
 #if defined (FBIO_GETWINORG)
if (value == FBIO_GETWINORG)
	return ("FBIO_GETWINORG");
#endif
 #if defined (FBIOSATTR)
if (value == FBIOSATTR)
	return ("FBIOSATTR");
#endif
 #if defined (TIOCSDRAINWAIT)
if (value == TIOCSDRAINWAIT)
	return ("TIOCSDRAINWAIT");
#endif
 #if defined (CONS_CURSORTYPE)
if (value == CONS_CURSORTYPE)
	return ("CONS_CURSORTYPE");
#endif
 #if defined (TIOCMBIS)
if (value == TIOCMBIS)
	return ("TIOCMBIS");
#endif
 #if defined (MTIOCERRSTAT)
if (value == MTIOCERRSTAT)
	return ("MTIOCERRSTAT");
#endif
 #if defined (DIGIIO_SETALTPIN)
if (value == DIGIIO_SETALTPIN)
	return ("DIGIIO_SETALTPIN");
#endif
 #if defined (CHIOIELEM)
if (value == CHIOIELEM)
	return ("CHIOIELEM");
#endif
 #if defined (TIOCSETAW)
if (value == TIOCSETAW)
	return ("TIOCSETAW");
#endif
 #if defined (TIOCLBIS)
if (value == TIOCLBIS)
	return ("TIOCLBIS");
#endif
 #if defined (CONS_SAVERMODE)
if (value == CONS_SAVERMODE)
	return ("CONS_SAVERMODE");
#endif
 #if defined (MTIOCSETEOTMODEL)
if (value == MTIOCSETEOTMODEL)
	return ("MTIOCSETEOTMODEL");
#endif
 #if defined (VT_SETMODE)
if (value == VT_SETMODE)
	return ("VT_SETMODE");
#endif
 #if defined (TIOCMSET)
if (value == TIOCMSET)
	return ("TIOCMSET");
#endif
 #if defined (PPS_IOC_GETPARAMS)
if (value == PPS_IOC_GETPARAMS)
	return ("PPS_IOC_GETPARAMS");
#endif
 #if defined (DIOCGFWSECTORS)
if (value == DIOCGFWSECTORS)
	return ("DIOCGFWSECTORS");
#endif
 #if defined (FBIO_SETPALETTE)
if (value == FBIO_SETPALETTE)
	return ("FBIO_SETPALETTE");
#endif
 #if defined (DIOCGMEDIASIZE)
if (value == DIOCGMEDIASIZE)
	return ("DIOCGMEDIASIZE");
#endif
 #if defined (VT_LOCKSWITCH)
if (value == VT_LOCKSWITCH)
	return ("VT_LOCKSWITCH");
#endif
 #if defined (TIIOCGETSTATS)
if (value == TIIOCGETSTATS)
	return ("TIIOCGETSTATS");
#endif
 #if defined (PTIOCGETTIMEOUT)
if (value == PTIOCGETTIMEOUT)
	return ("PTIOCGETTIMEOUT");
#endif
 #if defined (TIOCLSET)
if (value == TIOCLSET)
	return ("TIOCLSET");
#endif
 #if defined (CDRIOCWRITESPEED)
if (value == CDRIOCWRITESPEED)
	return ("CDRIOCWRITESPEED");
#endif
 #if defined (VT_GETMODE)
if (value == VT_GETMODE)
	return ("VT_GETMODE");
#endif
 #if defined (DIOCGDINFO)
if (value == DIOCGDINFO)
	return ("DIOCGDINFO");
#endif
 #if defined (GIO_SCRNMAP)
if (value == GIO_SCRNMAP)
	return ("GIO_SCRNMAP");
#endif
 #if defined (MTIOCGETEOTMODEL)
if (value == MTIOCGETEOTMODEL)
	return ("MTIOCGETEOTMODEL");
#endif
 #if defined (MTIOCSLOCATE)
if (value == MTIOCSLOCATE)
	return ("MTIOCSLOCATE");
#endif
 #if defined (CDRIOCGETPROGRESS)
if (value == CDRIOCGETPROGRESS)
	return ("CDRIOCGETPROGRESS");
#endif
 #if defined (FBIOGTYPE)
if (value == FBIOGTYPE)
	return ("FBIOGTYPE");
#endif
 #if defined (TIOCMSDTRWAIT)
if (value == TIOCMSDTRWAIT)
	return ("TIOCMSDTRWAIT");
#endif
 #if defined (FBIO_SETMODE)
if (value == FBIO_SETMODE)
	return ("FBIO_SETMODE");
#endif
 #if defined (CDRIOCREADFORMATCAPS)
if (value == CDRIOCREADFORMATCAPS)
	return ("CDRIOCREADFORMATCAPS");
#endif
 #if defined (CONS_CURRENT)
if (value == CONS_CURRENT)
	return ("CONS_CURRENT");
#endif
 #if defined (CHIOPOSITION)
if (value == CHIOPOSITION)
	return ("CHIOPOSITION");
#endif
 #if defined (FBIOGETCMAPI)
if (value == FBIOGETCMAPI)
	return ("FBIOGETCMAPI");
#endif
 #if defined (FBIO_BLANK)
if (value == FBIO_BLANK)
	return ("FBIO_BLANK");
#endif
 #if defined (DIOCSDINFO)
if (value == DIOCSDINFO)
	return ("DIOCSDINFO");
#endif
 #if defined (FBIO_ADPTYPE)
if (value == FBIO_ADPTYPE)
	return ("FBIO_ADPTYPE");
#endif
 #if defined (DIOCWDINFO)
if (value == DIOCWDINFO)
	return ("DIOCWDINFO");
#endif
 #if defined (FIOGETOWN)
if (value == FIOGETOWN)
	return ("FIOGETOWN");
#endif
 #if defined (FBIOPUTCMAP)
if (value == FBIOPUTCMAP)
	return ("FBIOPUTCMAP");
#endif
 #if defined (TIOCGDRAINWAIT)
if (value == TIOCGDRAINWAIT)
	return ("TIOCGDRAINWAIT");
#endif
 #if defined (PTIOCSETTIMEOUT)
if (value == PTIOCSETTIMEOUT)
	return ("PTIOCSETTIMEOUT");
#endif
 #if defined (MTIOCRDSPOS)
if (value == MTIOCRDSPOS)
	return ("MTIOCRDSPOS");
#endif
 #if defined (CDIOCGETVOL)
if (value == CDIOCGETVOL)
	return ("CDIOCGETVOL");
#endif
 #if defined (GIO_ATTR)
if (value == GIO_ATTR)
	return ("GIO_ATTR");
#endif
 #if defined (CONS_BLANKTIME)
if (value == CONS_BLANKTIME)
	return ("CONS_BLANKTIME");
#endif
 #if defined (TIOCGETA)
if (value == TIOCGETA)
	return ("TIOCGETA");
#endif
 #if defined (TIOCGETC)
if (value == TIOCGETC)
	return ("TIOCGETC");
#endif
 #if defined (TIOCGETD)
if (value == TIOCGETD)
	return ("TIOCGETD");
#endif
 #if defined (MTIOCTOP)
if (value == MTIOCTOP)
	return ("MTIOCTOP");
#endif
 #if defined (MTIOCGET)
if (value == MTIOCGET)
	return ("MTIOCGET");
#endif
 #if defined (CDIOCPLAYTRACKS)
if (value == CDIOCPLAYTRACKS)
	return ("CDIOCPLAYTRACKS");
#endif
 #if defined (CDRIOCNEXTWRITEABLEADDR)
if (value == CDRIOCNEXTWRITEABLEADDR)
	return ("CDRIOCNEXTWRITEABLEADDR");
#endif
 #if defined (FBIOGINFO)
if (value == FBIOGINFO)
	return ("FBIOGINFO");
#endif
 #if defined (CDIOCSETVOL)
if (value == CDIOCSETVOL)
	return ("CDIOCSETVOL");
#endif
 #if defined (KDGETMODE)
if (value == KDGETMODE)
	return ("KDGETMODE");
#endif
 #if defined (TIOCFLUSH)
if (value == TIOCFLUSH)
	return ("TIOCFLUSH");
#endif
 #if defined (TIOCGETP)
if (value == TIOCGETP)
	return ("TIOCGETP");
#endif
 #if defined (KDGKBSTATE)
if (value == KDGKBSTATE)
	return ("KDGKBSTATE");
#endif
 #if defined (DIOCGFWHEADS)
if (value == DIOCGFWHEADS)
	return ("DIOCGFWHEADS");
#endif
 #if defined (FBIO_SETLINEWIDTH)
if (value == FBIO_SETLINEWIDTH)
	return ("FBIO_SETLINEWIDTH");
#endif
 #if defined (FBIOGVIDEO)
if (value == FBIOGVIDEO)
	return ("FBIOGVIDEO");
#endif
 #if defined (FBIO_ADPINFO)
if (value == FBIO_ADPINFO)
	return ("FBIO_ADPINFO");
#endif
 #if defined (TIOCUCNTL)
if (value == TIOCUCNTL)
	return ("TIOCUCNTL");
#endif
 #if defined (DIGIIO_GETALTPIN)
if (value == DIGIIO_GETALTPIN)
	return ("DIGIIO_GETALTPIN");
#endif
 #if defined (TIOCSLTC)
if (value == TIOCSLTC)
	return ("TIOCSLTC");
#endif
 #if defined (TIOCMGET)
if (value == TIOCMGET)
	return ("TIOCMGET");
#endif
 #if defined (SIOCSDRVSPEC)
if (value == SIOCSDRVSPEC)
	return ("SIOCSDRVSPEC");
#endif
 #if defined (TIOCGPGRP)
if (value == TIOCGPGRP)
	return ("TIOCGPGRP");
#endif
 #if defined (MEMRANGE_SET)
if (value == MEMRANGE_SET)
	return ("MEMRANGE_SET");
#endif
 #if defined (FBIOPUTCMAPI)
if (value == FBIOPUTCMAPI)
	return ("FBIOPUTCMAPI");
#endif
 #if defined (KDSETREPEAT)
if (value == KDSETREPEAT)
	return ("KDSETREPEAT");
#endif
 #if defined (CDRIOCGETBLOCKSIZE)
if (value == CDRIOCGETBLOCKSIZE)
	return ("CDRIOCGETBLOCKSIZE");
#endif
 #if defined (FBIOSCURPOS)
if (value == FBIOSCURPOS)
	return ("FBIOSCURPOS");
#endif
 #if defined (CONS_SSAVER)
if (value == CONS_SSAVER)
	return ("CONS_SSAVER");
#endif
 #if defined (GIO_COLOR)
if (value == GIO_COLOR)
	return ("GIO_COLOR");
#endif
 #if defined (DIOCBSDBB)
if (value == DIOCBSDBB)
	return ("DIOCBSDBB");
#endif
 #if defined (FBIOSVIDEO)
if (value == FBIOSVIDEO)
	return ("FBIOSVIDEO");
#endif
 #if defined (TIOCLGET)
if (value == TIOCLGET)
	return ("TIOCLGET");
#endif
 #if defined (CDIOCPLAYBLOCKS)
if (value == CDIOCPLAYBLOCKS)
	return ("CDIOCPLAYBLOCKS");
#endif
 #if defined (KDRASTER)
if (value == KDRASTER)
	return ("KDRASTER");
#endif
 #if defined (MOUSE_SETSCALING)
if (value == MOUSE_SETSCALING)
	return ("MOUSE_SETSCALING");
#endif
 #if defined (PIO_SCRNMAP)
if (value == PIO_SCRNMAP)
	return ("PIO_SCRNMAP");
#endif
 #if defined (TIIOCSETPARAMS)
if (value == TIIOCSETPARAMS)
	return ("TIIOCSETPARAMS");
#endif
 #if defined (FIONREAD)
if (value == FIONREAD)
	return ("FIONREAD");
#endif
 #if defined (MOUSE_SYN_GETHWINFO)
if (value == MOUSE_SYN_GETHWINFO)
	return ("MOUSE_SYN_GETHWINFO");
#endif
 #if defined (CONS_CURRENTADP)
if (value == CONS_CURRENTADP)
	return ("CONS_CURRENTADP");
#endif
 #if defined (CONS_SAVERSTART)
if (value == CONS_SAVERSTART)
	return ("CONS_SAVERSTART");
#endif
 #if defined (TIOCMGDTRWAIT)
if (value == TIOCMGDTRWAIT)
	return ("TIOCMGDTRWAIT");
#endif
 #if defined (VT_OPENQRY)
if (value == VT_OPENQRY)
	return ("VT_OPENQRY");
#endif
 #if defined (FBIOGETCMAP)
if (value == FBIOGETCMAP)
	return ("FBIOGETCMAP");
#endif
 #if defined (KDGETLED)
if (value == KDGETLED)
	return ("KDGETLED");
#endif
 #if defined (SNDCTL_DSP_GETBLKSIZE)
if (value == SNDCTL_DSP_GETBLKSIZE)
	return ("SNDCTL_DSP_GETBLKSIZE");
#endif
 #if defined (FBIOGCURPOS)
if (value == FBIOGCURPOS)
	return ("FBIOGCURPOS");
#endif
 #if defined (FIOGETLBA)
if (value == FIOGETLBA)
	return ("FIOGETLBA");
#endif
 #if defined (CONS_BELLTYPE)
if (value == CONS_BELLTYPE)
	return ("CONS_BELLTYPE");
#endif
 #if defined (CDRIOCSETBLOCKSIZE)
if (value == CDRIOCSETBLOCKSIZE)
	return ("CDRIOCSETBLOCKSIZE");
#endif
 #if defined (CDIOCSETPATCH)
if (value == CDIOCSETPATCH)
	return ("CDIOCSETPATCH");
#endif
 #if defined (FBIO_SETWINORG)
if (value == FBIO_SETWINORG)
	return ("FBIO_SETWINORG");
#endif
 #if defined (KDGKBTYPE)
if (value == KDGKBTYPE)
	return ("KDGKBTYPE");
#endif
 #if defined (FBIO_GETDISPSTART)
if (value == FBIO_GETDISPSTART)
	return ("FBIO_GETDISPSTART");
#endif
 #if defined (CHIOGPARAMS)
if (value == CHIOGPARAMS)
	return ("CHIOGPARAMS");
#endif
 #if defined (CONS_IDLE)
if (value == CONS_IDLE)
	return ("CONS_IDLE");
#endif
 #if defined (CHIOMOVE)
if (value == CHIOMOVE)
	return ("CHIOMOVE");
#endif
 #if defined (WDIOCPATPAT)
if (value == WDIOCPATPAT)
	return ("WDIOCPATPAT");
#endif
 #if defined (DIOCGSECTORSIZE)
if (value == DIOCGSECTORSIZE)
	return ("DIOCGSECTORSIZE");
#endif
 #if defined (CHIOGSTATUS)
if (value == CHIOGSTATUS)
	return ("CHIOGSTATUS");
#endif
 #if defined (TIOCSPGRP)
if (value == TIOCSPGRP)
	return ("TIOCSPGRP");
#endif
 
	return ("");
}

