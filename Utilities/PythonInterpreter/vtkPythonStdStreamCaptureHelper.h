/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPythonStdStreamCaptureHelper.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkPythonStdStreamCaptureHelper
 *
 */

#ifndef vtkPythonStdStreamCaptureHelper_h
#define vtkPythonStdStreamCaptureHelper_h

#include "structmember.h"
#include "vtkPythonCompatibility.h"
#include "vtkPythonInterpreter.h"

VTK_ABI_NAMESPACE_BEGIN
struct vtkPythonStdStreamCaptureHelper
{
  PyObject_HEAD
  int softspace; // Used by print to keep track of its state.
  bool DumpToError;

  void Write(const char* string)
  {
    if (this->DumpToError)
    {
      vtkPythonInterpreter::WriteStdErr(string);
    }
    else
    {
      vtkPythonInterpreter::WriteStdOut(string);
    }
  }

  void Flush()
  {
    if (this->DumpToError)
    {
      vtkPythonInterpreter::FlushStdErr();
    }
    else
    {
      vtkPythonInterpreter::FlushStdOut();
    }
  }

  vtkStdString Read() { return vtkPythonInterpreter::ReadStdin(); }

  bool IsATTY()
  {
    if (vtkPythonInterpreter::GetCaptureStdin())
    {
      return false;
    }
    return isatty(fileno(stdin)); // when not captured, uses cin
  }
  void Close() { this->Flush(); }
};

static PyObject* vtkWrite(PyObject* self, PyObject* args);
static PyObject* vtkRead(PyObject* self, PyObject* args);
static PyObject* vtkFlush(PyObject* self, PyObject* args);
static PyObject* vtkIsatty(PyObject* self, PyObject* args);
static PyObject* vtkClose(PyObject* self, PyObject* args);

// const_cast since older versions of python are not const correct.
static PyMethodDef vtkPythonStdStreamCaptureHelperMethods[] = {
  { const_cast<char*>("write"), vtkWrite, METH_VARARGS, const_cast<char*>("Dump message") },
  { const_cast<char*>("readline"), vtkRead, METH_VARARGS, const_cast<char*>("Read input line") },
  { const_cast<char*>("flush"), vtkFlush, METH_VARARGS, const_cast<char*>("Flush") },
  { const_cast<char*>("isatty"), vtkIsatty, METH_VARARGS, const_cast<char*>("Is a TTY") },
  { const_cast<char*>("close"), vtkClose, METH_VARARGS, const_cast<char*>("Close") }, { 0, 0, 0, 0 }
};

static PyObject* vtkPythonStdStreamCaptureHelperNew(
  PyTypeObject* type, PyObject* /*args*/, PyObject* /*kwds*/)
{
  return type->tp_alloc(type, 0);
}

static PyMemberDef vtkPythonStdStreamCaptureHelperMembers[] = {
  { const_cast<char*>("softspace"), T_INT, offsetof(vtkPythonStdStreamCaptureHelper, softspace), 0,
    const_cast<char*>("Placeholder so print can keep state.") },
  { 0, 0, 0, 0, 0 }
};

#ifdef VTK_PYTHON_NEEDS_DEPRECATION_WARNING_SUPPRESSION
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

// clang-format off
static PyTypeObject vtkPythonStdStreamCaptureHelperType = {
  PyVarObject_HEAD_INIT(&PyType_Type, 0)
  "vtkPythonStdStreamCaptureHelper",       // tp_name
  sizeof(vtkPythonStdStreamCaptureHelper), // tp_basicsize
  0,                                       // tp_itemsize
  0,                                       // tp_dealloc
#if PY_VERSION_HEX >= 0x03080000
  0, // tp_vectorcall_offset
#else
  nullptr, // tp_print
#endif
  0,                                        // tp_getattr
  0,                                        // tp_setattr
  0,                                        // tp_compare
  0,                                        // tp_repr
  0,                                        // tp_as_number
  0,                                        // tp_as_sequence
  0,                                        // tp_as_mapping
  0,                                        // tp_hash
  0,                                        // tp_call
  0,                                        // tp_str
  PyObject_GenericGetAttr,                  // tp_getattro
  PyObject_GenericSetAttr,                  // tp_setattro
  0,                                        // tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, // tp_flags
  "vtkPythonStdStreamCaptureHelper",        //  tp_doc
  0,                                        //  tp_traverse
  0,                                        //  tp_clear
  0,                                        //  tp_richcompare
  0,                                        //  tp_weaklistoffset
  0,                                        //  tp_iter
  0,                                        //  tp_iternext
  vtkPythonStdStreamCaptureHelperMethods,   //  tp_methods
  vtkPythonStdStreamCaptureHelperMembers,   //  tp_members
  0,                                        //  tp_getset
  0,                                        //  tp_base
  0,                                        //  tp_dict
  0,                                        //  tp_descr_get
  0,                                        //  tp_descr_set
  0,                                        //  tp_dictoffset
  0,                                        //  tp_init
  0,                                        //  tp_alloc
  vtkPythonStdStreamCaptureHelperNew,       //  tp_new
  0,                                        // freefunc tp_free; /* Low-level free-memory routine */
  0,                                        // inquiry tp_is_gc; /* For PyObject_IS_GC */
  0,                                        // PyObject *tp_bases;
  0,                                        // PyObject *tp_mro; /* method resolution order */
  0,                                        // PyObject *tp_cache;
  0,                                        // PyObject *tp_subclasses;
  0,                                        // PyObject *tp_weaklist;
  VTK_WRAP_PYTHON_SUPPRESS_UNINITIALIZED
};
// clang-format on

static PyObject* vtkWrite(PyObject* self, PyObject* args)
{
  if (!self || !PyObject_TypeCheck(self, &vtkPythonStdStreamCaptureHelperType))
  {
    return 0;
  }

  vtkPythonStdStreamCaptureHelper* wrapper =
    reinterpret_cast<vtkPythonStdStreamCaptureHelper*>(self);

  char* string;
  // const_cast since older versions of python are not const correct.
  if (wrapper && PyArg_ParseTuple(args, "s", &string))
  {
    wrapper->Write(string);
  }
  return Py_BuildValue("");
}

static PyObject* vtkRead(PyObject* self, PyObject* args)
{
  (void)args;
  if (!self || !PyObject_TypeCheck(self, &vtkPythonStdStreamCaptureHelperType))
  {
    return 0;
  }

  vtkPythonStdStreamCaptureHelper* wrapper =
    reinterpret_cast<vtkPythonStdStreamCaptureHelper*>(self);

  vtkStdString ret;
  if (wrapper)
  {
    ret = wrapper->Read();
  }
  return Py_BuildValue("s", ret.c_str());
}

static PyObject* vtkFlush(PyObject* self, PyObject* args)
{
  (void)args;
  if (!self || !PyObject_TypeCheck(self, &vtkPythonStdStreamCaptureHelperType))
  {
    return 0;
  }

  vtkPythonStdStreamCaptureHelper* wrapper =
    reinterpret_cast<vtkPythonStdStreamCaptureHelper*>(self);
  if (wrapper)
  {
    wrapper->Flush();
  }
  return Py_BuildValue("");
}

static PyObject* vtkIsatty(PyObject* self, PyObject* args)
{
  (void)args;
  if (!self || !PyObject_TypeCheck(self, &vtkPythonStdStreamCaptureHelperType))
  {
    return 0;
  }
  vtkPythonStdStreamCaptureHelper* wrapper =
    reinterpret_cast<vtkPythonStdStreamCaptureHelper*>(self);
  if (wrapper->IsATTY())
  {
    Py_INCREF(Py_True);
    return Py_True;
  }
  Py_INCREF(Py_False);
  return Py_False;
}

static PyObject* vtkClose(PyObject* self, PyObject* args)
{
  (void)args;
  if (!self || !PyObject_TypeCheck(self, &vtkPythonStdStreamCaptureHelperType))
  {
    return 0;
  }

  vtkPythonStdStreamCaptureHelper* wrapper =
    reinterpret_cast<vtkPythonStdStreamCaptureHelper*>(self);
  if (wrapper)
  {
    wrapper->Close();
  }
  return Py_BuildValue("");
}

static vtkPythonStdStreamCaptureHelper* NewPythonStdStreamCaptureHelper(bool for_stderr = false)
{
  vtkPythonScopeGilEnsurer gilEnsurer;
  if (PyType_Ready(&vtkPythonStdStreamCaptureHelperType) < 0)
  {
    return 0;
  }

  vtkPythonStdStreamCaptureHelper* wrapper =
    PyObject_New(vtkPythonStdStreamCaptureHelper, &vtkPythonStdStreamCaptureHelperType);
  if (wrapper)
  {
    wrapper->DumpToError = for_stderr;
  }

  return wrapper;
}

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: vtkPythonStdStreamCaptureHelper.h
