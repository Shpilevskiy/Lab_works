﻿================================================================================
    БИБЛИОТЕКА MICROSOFT FOUNDATION CLASS. Обзор проекта DrawApp
===============================================================================

Это приложение DrawApp автоматически создано с помощью мастера приложений. Это приложение демонстрирует основные принципы использования классов Microsoft Foundation; оно также может использоваться в качестве основы для написания собственных приложений.

В этом файле представлена сводка содержимого всех файлов, входящих в состав приложения DrawApp.

DrawApp.vcxproj
    Это основной файл проекта VC++, создаваемый с помощью мастера приложений. Он содержит данные о версии языка Visual C++, использованной для создания файла, а также сведения о платформах, конфигурациях и функциях проекта, выбранных с помощью мастера приложений.

DrawApp.vcxproj.filters
    Это файл фильтров для проектов VC++, созданный с помощью мастера приложений. Он содержит сведения о сопоставлениях между файлами в вашем проекте и фильтрами. Эти сопоставления используются в среде IDE для группировки файлов с одинаковыми расширениями в одном узле (например CPP-файлы сопоставляются с фильтром "Исходные файлы").

DrawApp.h
    Это основной файл заголовка приложения.
    Он содержит прочие заголовки, относящиеся к проекту (включая Resource.h), а также объявляет класс приложения CDrawAppApp.

DrawApp.cpp
    Это основной исходный файл приложения, в котором содержится класс приложения CDrawAppApp.

DrawApp.rc
    Он представляет собой список всех ресурсов Microsoft Windows, используемых программой. В него включены значки, точечные рисунки и курсоры, хранящиеся в подкаталоге RES. Этот файл можно редактировать непосредственно в Microsoft Visual C++. Ресурсы проекта находятся в 1049.

res\DrawApp.ico
    Файл значка, используемый в качестве значка приложения. Этот значок включен с помощью основного файла ресурсов DrawApp.rc.

res\DrawApp.rc2
    Этот файл содержит ресурсы, которые нельзя редактировать в Microsoft Visual C++. В этот файл следует поместить все ресурсы, не редактируемые редактором ресурсов.

/////////////////////////////////////////////////////////////////////////////

Для окна главного фрейма:
    Проект включает стандартный интерфейс MFC.

MainFrm.h, MainFrm.cpp
    Эти файлы содержат класс фрейма CMainFrame, который является производным от класса
    CFrameWnd и управляет всеми функциями фрейма SDI.

res\Toolbar.bmp
    Этот файл точечного рисунка используется при создании мозаичных изображений для панели инструментов.
    Начальная панель инструментов и строка состояния, созданные в классе CMainFrame. Измените этот точечный рисунок панели инструментов в редакторе ресурсов и обновите массив IDR_MAINFRAME TOOLBAR в файле DrawApp.rc, чтобы добавить кнопки панели инструментов.
/////////////////////////////////////////////////////////////////////////////

Мастер приложений создает один тип документов и одно представление:

DrawAppDoc.h, DrawAppDoc.cpp — документ
    Эти файлы содержат класс CDrawAppDoc. Измените эти файлы, чтобы добавить особые данные документа и реализовать сохранение и загрузку файлов (посредством CDrawAppDoc::Serialize).

DrawAppView.h, DrawAppView.cpp — представление документа
    Эти файлы содержат класс CDrawAppView.
    Объекты CDrawAppView используются для просмотра объектов CDrawAppDoc.




/////////////////////////////////////////////////////////////////////////////

Другие возможности.

Элементы управления ActiveX
    Приложение включает поддержку элементов управления ActiveX.

/////////////////////////////////////////////////////////////////////////////

Другие стандартные файлы:

StdAfx.h, StdAfx.cpp
    Эти файлы используются для построения файла предкомпилированного заголовка (PCH) с именем DrawApp.pch и файла предкомпилированных типов с именем StdAfx.obj.

Resource.h
    Это стандартный файл заголовка, в котором определяются новые идентификаторы ресурсов. Такой файл можно прочитать и обновить в Microsoft Visual C++.

DrawApp.manifest
	Файлы манифеста приложения используются операционной системой Windows XP для описания зависимости приложений от определенных версий параллельных сборок. Эти сведения используются загрузчиком для загрузки соответствующей сборки из кэша сборок или частным образом из приложения. Манифест приложения можно включить для распространения в качестве внешнего MANIFEST-файла, устанавливаемого в одной папке с исполняемым файлом приложения, или внедрить в исполняемый файл в виде ресурса.
/////////////////////////////////////////////////////////////////////////////

Прочие примечания.

С помощью комментариев «TODO:» в мастере приложений обозначаются фрагменты исходного кода, которые необходимо дополнить или изменить.

Если приложение использует MFC в общей библиотеке DLL, необходимо обеспечить распространение библиотек DLL MFC. Если в приложении используется язык, отличный от языка операционной системы, потребуется также обеспечить распространение соответствующих локализованных ресурсов mfc110XXX.DLL.
Дополнительные сведения о выполнении этих задач см. в разделе документации MSDN, посвященном распространению приложений Visual C++.

/////////////////////////////////////////////////////////////////////////////
