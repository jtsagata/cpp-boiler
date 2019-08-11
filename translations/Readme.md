## To add a new translation language

* Init the translation file
  msginit --input=cpp-boiler.pot --locale=el_GR.UTF-8 --output=el.po --no-translator
* Add files tο LINGUAS
  echo el >> LINGUAS