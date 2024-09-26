#include "py_interface.h"

char* gen_password(const char* seed, int size) {
	PyObject *py_module, *py_gen_password, *args, *new_password;

	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	py_module = PyImport_Import(PyUnicode_DecodeFSDefault("password_generator"));

	py_gen_password = PyObject_GetAttrString(py_module, "gen_password");

	args = PyTuple_New(2);    
	PyTuple_SetItem(args, 0, PyUnicode_FromString(seed));
	PyTuple_SetItem(args, 1, PyLong_FromLong(size));

	new_password = PyObject_CallObject(py_gen_password, args);
	
	Py_DECREF(args);

	PyObject *temp_bytes = PyUnicode_AsEncodedString(new_password, "UTF-8", NULL);
	char* result = PyBytes_AS_STRING(temp_bytes);
	Py_DECREF(temp_bytes);
    
	Py_DECREF(new_password);
	Py_DECREF(py_gen_password);
	Py_DECREF(py_module);

	Py_Finalize();
	return result;
}
