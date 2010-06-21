// Generated from formcap.js
const QString jscode_formcap_js = QString::fromUtf8(
   "\n"
   "\n"
   "\n"
   "$.fn.serializeObject = function(){\n"
   "    var object = {};\n"
   "    var sArray = this.serializeArray();\n"
   "    $.each(sArray , function() {\n"
   "        if (object[this.name]) {\n"
   "            if (!object[this.name].push) {\n"
   "                object[this.name] = [object[this.name]];\n"
   "            }\n"
   "            object[this.name].push(this.value || '');\n"
   "        } else {\n"
   "            object[this.name] = this.value || '';\n"
   "        }\n"
   "    });\n"
   "    return object;\n"
   "};\n"
   "var POST = MyQObject.getPost();\n"
   "var GET = MyQObject.getGet();\n"
   "function MyLibSubmit(form_selector) {\n"
   "	var ob = $(form_selector).serializeObject();\n"
   "	if ($(form_selector).attr('method').toLowerCase() == 'post') {\n"
   "		MyQObject.setPost(ob);\n"
   "	} else {\n"
   "		MyQObject.setGet(ob);\n"
   "	}\n"
   "	return true;\n"
   "}\n"
   ); // jscode_formcap_js
