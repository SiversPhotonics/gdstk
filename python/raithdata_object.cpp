static PyObject* raithdata_object_str(RaithDataObject* self) {
    char buffer[GDSTK_PRINT_BUFFER_COUNT];
    snprintf(
        buffer, COUNT(buffer),
        "RaithData(dwelltime_selection: %d, pitch_parallel_to_path: %lg, pitch_perpendicular_to_path: %lg, pitch_scale: %lg, periods: %d, grating_type: %d, dots_per_cycle: %d)",
        self->raithdata.dwelltime_selection, self->raithdata.pitch_parallel_to_path,
        self->raithdata.pitch_perpendicular_to_path, self->raithdata.pitch_scale,
        self->raithdata.periods, self->raithdata.grating_type, self->raithdata.dots_per_cycle);
    return PyUnicode_FromString(buffer);
}

static void raithdata_object_dealloc(RaithDataObject* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static int raithdata_object_init(RaithDataObject* self, PyObject* args, PyObject* kwds) {
    const char* keywords[] = {"dwelltime_selection",
                              "pitch_parallel_to_path",
                              "pitch_perpendicular_to_path",
                              "pitch_scale",
                              "periods",
                              "grating_type",
                              "dots_per_cycle",
                              NULL};
    unsigned int dwelltime_selection = 0;
    double pitch_parallel_to_path = 0;
    double pitch_perpendicular_to_path = 0;
    double pitch_scale = 0;
    int periods = 0;
    int grating_type = 0;
    int dots_per_cycle = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|idddiii:RaithData", (char**)keywords,
                                     &dwelltime_selection, &pitch_parallel_to_path,
                                     &pitch_perpendicular_to_path, &pitch_scale, &periods,
                                     &grating_type, &dots_per_cycle))
        return -1;

    RaithData* raithdata = &self->raithdata;

    raithdata->dwelltime_selection = (uint8_t)dwelltime_selection;
    raithdata->pitch_parallel_to_path = pitch_parallel_to_path;
    raithdata->pitch_perpendicular_to_path = pitch_perpendicular_to_path;
    raithdata->pitch_scale = pitch_scale;
    raithdata->periods = (int32_t)periods;
    raithdata->grating_type = (int32_t)grating_type;
    raithdata->dots_per_cycle = (int32_t)dots_per_cycle;
    raithdata->owner = self;
    return 0;
}

static PyMethodDef raithdata_object_methods[] = {{NULL}};

static PyObject* raithdata_object_get_dwelltime_selection(RaithDataObject* self, void*) {
    return PyLong_FromUnsignedLong(self->raithdata.dwelltime_selection);
}

int raithdata_object_set_dwelltime_selection(RaithDataObject* self, PyObject* value, void*) {
    if (!PyLong_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "The dwelltime_selection attribute value must be an integer.");
        return -1;
    }
    self->raithdata.dwelltime_selection = PyLong_AsUnsignedLong(value);
    return 0;
}

static PyObject* raithdata_object_get_pitch_parallel_to_path(RaithDataObject* self, void*) {
    return PyFloat_FromDouble(self->raithdata.pitch_parallel_to_path);
}

int raithdata_object_set_pitch_parallel_to_path(RaithDataObject* self, PyObject* value, void*) {
    double new_value = PyFloat_AsDouble(value);
    if (PyErr_Occurred()) {
        PyErr_SetString(PyExc_TypeError,
                        "The pitch_parallel_to_path attribute value must be a float.");
        return -1;
    }
    self->raithdata.pitch_parallel_to_path = new_value;
    return 0;
}

static PyObject* raithdata_object_get_pitch_perpendicular_to_path(RaithDataObject* self, void*) {
    return PyFloat_FromDouble(self->raithdata.pitch_perpendicular_to_path);
}

int raithdata_object_set_pitch_perpendicular_to_path(RaithDataObject* self, PyObject* value,
                                                     void*) {
    double new_value = PyFloat_AsDouble(value);
    if (PyErr_Occurred()) {
        PyErr_SetString(PyExc_TypeError,
                        "The pitch_perpendicular_to_path attribute value must be a float.");
        return -1;
    }
    self->raithdata.pitch_perpendicular_to_path = new_value;
    return 0;
}

static PyObject* raithdata_object_get_pitch_scale(RaithDataObject* self, void*) {
    return PyFloat_FromDouble(self->raithdata.pitch_scale);
}

int raithdata_object_set_pitch_scale(RaithDataObject* self, PyObject* value, void*) {
    double new_value = PyFloat_AsDouble(value);
    if (PyErr_Occurred()) {
        PyErr_SetString(PyExc_TypeError, "The pitch_scale attribute value must be a float.");
        return -1;
    }
    self->raithdata.pitch_scale = new_value;
    return 0;
}

static PyObject* raithdata_object_get_periods(RaithDataObject* self, void*) {
    return PyLong_FromUnsignedLong(self->raithdata.periods);
}

int raithdata_object_set_periods(RaithDataObject* self, PyObject* value, void*) {
    if (!PyLong_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "The periods attribute value must be an integer.");
        return -1;
    }
    self->raithdata.periods = PyLong_AsUnsignedLong(value);
    return 0;
}

static PyObject* raithdata_object_get_grating_type(RaithDataObject* self, void*) {
    return PyLong_FromUnsignedLong(self->raithdata.grating_type);
}

int raithdata_object_set_grating_type(RaithDataObject* self, PyObject* value, void*) {
    if (!PyLong_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "The grating_type attribute value must be an integer.");
        return -1;
    }
    self->raithdata.grating_type = PyLong_AsUnsignedLong(value);
    return 0;
}

static PyObject* raithdata_object_get_dots_per_cycle(RaithDataObject* self, void*) {
    return PyLong_FromUnsignedLong(self->raithdata.dots_per_cycle);
}

int raithdata_object_set_dots_per_cycle(RaithDataObject* self, PyObject* value, void*) {
    if (!PyLong_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "The dots_per_cycle attribute value must be an integer.");
        return -1;
    }
    self->raithdata.dots_per_cycle = PyLong_AsUnsignedLong(value);
    return 0;
}

static PyGetSetDef raithdata_object_getset[] = {
    {"dwelltime_selection", (getter)raithdata_object_get_dwelltime_selection,
     (setter)raithdata_object_set_dwelltime_selection, raithdata_object_dwelltime_selection_doc,
     NULL},
    {"pitch_parallel_to_path", (getter)raithdata_object_get_pitch_parallel_to_path,
     (setter)raithdata_object_set_pitch_parallel_to_path,
     raithdata_object_pitch_parallel_to_path_doc, NULL},
    {"pitch_perpendicular_to_path", (getter)raithdata_object_get_pitch_perpendicular_to_path,
     (setter)raithdata_object_pitch_perpendicular_to_path_doc,
     raithdata_object_pitch_parallel_to_path_doc, NULL},
    {"pitch_scale", (getter)raithdata_object_get_pitch_scale,
     (setter)raithdata_object_set_pitch_scale, raithdata_object_pitch_scale_doc, NULL},
    {"periods", (getter)raithdata_object_get_periods, (setter)raithdata_object_set_periods,
     raithdata_object_periods_doc, NULL},
    {"grating_type", (getter)raithdata_object_get_grating_type,
     (setter)raithdata_object_set_grating_type, grating_type_object_type_doc, NULL},
    {"dots_per_cycle", (getter)raithdata_object_get_dots_per_cycle,
     (setter)raithdata_object_set_dots_per_cycle, dots_per_cycle_object_type_doc, NULL},
    {NULL}};
