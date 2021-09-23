
add_library(Qt5::QTextToSpeechPluginWinRT MODULE IMPORTED)


_populate_TextToSpeech_plugin_properties(QTextToSpeechPluginWinRT RELEASE "texttospeech/qtexttospeech_winrt.dll" TRUE)
_populate_TextToSpeech_plugin_properties(QTextToSpeechPluginWinRT DEBUG "texttospeech/qtexttospeech_winrtd.dll" TRUE)

list(APPEND Qt5TextToSpeech_PLUGINS Qt5::QTextToSpeechPluginWinRT)
set_property(TARGET Qt5::TextToSpeech APPEND PROPERTY QT_ALL_PLUGINS_texttospeech Qt5::QTextToSpeechPluginWinRT)
set_property(TARGET Qt5::QTextToSpeechPluginWinRT PROPERTY QT_PLUGIN_TYPE "texttospeech")
set_property(TARGET Qt5::QTextToSpeechPluginWinRT PROPERTY QT_PLUGIN_EXTENDS "")
