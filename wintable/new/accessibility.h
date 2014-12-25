// 24 december 2014

struct tableAcc {
	IAccessibleVtbl vtbl;
	ULONG refcount;
	struct table *t;
};

static HRESULT STDMETHODCALLTYPE tableAccQueryInterface(IAccessible *this, REFIID riid, void **ppvObject)
{
	if (ppvObject == NULL)
		return E_POINTER;
	if (IsEqualIID(riid, &IID_IUnknown) ||
		IsEqualIID(riid, &IID_IDispatch) ||
		IsEqualIID(riid, &IID_IAccessible)) {
		*ppvObject = (void *) this;
		return S_OK;
	}
	*ppvObject = NULL;
	return E_NOINTERFACE;
}

#define TA ((struct tableAcc *) this)

// TODO use InterlockedIncrement()/InterlockedDecrement() for these?

static ULONG STDMETHODCALLTYPE tableAccAddRef(IAccessible *this)
{
	TA->refcount++;
	return TA->refcount;
}

static ULONG STDMETHODCALLTYPE tableAccRelease(IAccessible *this)
{
	TA->refcount--;
	if (TA->refcount == 0) {
		tableFree(TA, "error freeing Table accessibility object");
		return 0;
	}
	return TA->refcount;
}

// disregard IDispatch: http://msdn.microsoft.com/en-us/library/windows/desktop/cc307844.aspx
// TODO DISP_E_MEMBERNOTFOUND? http://blogs.msdn.com/b/saraford/archive/2004/08/20/which-controls-support-which-msaa-properties-and-how-these-controls-implement-msaa-properties.aspx

static HRESULT STDMETHODCALLTYPE tableAccGetTypeInfoCount(IAccessible *this, UINT *pctinfo)
{
	if (pctinfo == NULL)
		return E_INVALIDARG;
	// TODO assign something to *pctinfo?
	return E_NOTIMPL;
}

static HRESULT STDMETHODCALLTYPE tableAccGetTypeInfo(IAccessible *this, UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
{
	if (ppTInfo == NULL)
		return E_INVALIDARG;
	*ppTInfo = NULL;
	return E_NOTIMPL;
}

static HRESULT STDMETHODCALLTYPE tableAccGetIDsOfNames(IAccessible *this, REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
	// TODO verify this one
	if (rgDispId == NULL)
		return E_INVALIDARG;
	// TODO overwrite rgDispId?
	return E_NOTIMPL;
}

static HRESULT STDMETHODCALLTYPE tableAccInvoke(IAccessible *this, DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
	// TODO check this one
	return E_NOTIMPL;
}

// IAccessible

static HRESULT STDMETHODCALLTYPE tableAccget_accParent(IAccessible *this, IDispatch **ppdispParent)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accChildCount(IAccessible *this, long *pcountChildren)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accChild(IAccessible *this, VARIANT varChild, IDispatch **ppdispChild)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accName(IAccessible *this, VARIANT varChild, BSTR *pszName)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accValue(IAccessible *this, VARIANT varChild, BSTR *pszValue)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accDescription(IAccessible *this, VARIANT varChild, BSTR *pszDescription)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accRole(IAccessible *this, VARIANT varChild, VARIANT *pvarRole)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accState(IAccessible *this, VARIANT varChild, VARIANT *pvarState)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accHelp(IAccessible *this, VARIANT varChild, BSTR *pszHelp)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accHelpTopic(IAccessible *this, BSTR *pszHelpFile, VARIANT varChild, long *pidTopic)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accKeyboardShortcut(IAccessible *this, VARIANT varChild, BSTR *pszKeyboardShortcut)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accFocus(IAccessible *this, VARIANT *pvarChild)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accSelection(IAccessible *this, VARIANT *pvarChildren)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccget_accDefaultAction(IAccessible *this, VARIANT varChild, BSTR *pszDefaultAction)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccaccSelect(IAccessible *this, long flagsSelect, VARIANT varChild)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccaccLocation(IAccessible *this, long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccaccNavigate(IAccessible *this, long navDir, VARIANT varStart, VARIANT *pvarEndUpAt)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccaccHitTest(IAccessible *this, long xLeft, long yTop, VARIANT *pvarChild)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccaccDoDefaultAction(IAccessible *this, VARIANT varChild)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccput_accName(IAccessible *this, VARIANT varChild, BSTR szName)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static HRESULT STDMETHODCALLTYPE tableAccput_accValue(IAccessible *this, VARIANT varChild, BSTR szValue)
{
	// TODO
	return DISP_E_MEMBERNOTFOUND;
}

static const IAccessibleVtbl tableAccVtbl = {
	.QueryInterface = tableAccQueryInterface,
	.AddRef = tableAccAddRef,
	.Release = tableAccRelease,
	.GetTypeInfoCount = tableAccGetTypeInfoCount,
	.GetTypeInfo = tableAccGetTypeInfo,
	.GetIDsOfNames = tableAccGetIDsOfNames,
	.Invoke = tableAccInvoke,
	.get_accParent = tableAccget_accParent,
	.get_accChildCount = tableAccget_accChildCount,
	.get_accChild = tableAccget_accChild,
	.get_accName = tableAccget_accName,
	.get_accValue = tableAccget_accValue,
	.get_accDescription = tableAccget_accDescription,
	.get_accRole = tableAccget_accRole,
	.get_accState = tableAccget_accState,
	.get_accHelp = tableAccget_accHelp,
	.get_accHelpTopic = tableAccget_accHelpTopic,
	.get_accKeyboardShortcut = tableAccget_accKeyboardShortcut,
	.get_accFocus = tableAccget_accFocus,
	.get_accSelection = tableAccget_accSelection,
	.get_accDefaultAction = tableAccget_accDefaultAction,
	.accSelect = tableAccaccSelect,
	.accLocation = tableAccaccLocation,
	.accNavigate = tableAccaccNavigate,
	.accHitTest = tableAccaccHitTest,
	.accDoDefaultAction = tableAccaccDoDefaultAction,
	.put_accName = tableAccput_accName,
	.put_accValue = tableAccput_accValue,
};

static struct tableAcc *newTableAcc(struct table *t)
{
	struct tableAcc *ta;

	ta = (struct tableAcc *) tableAlloc(sizeof (struct tableAcc), "error creating Table accessibility object");
	ta->vtbl = tableAccVtbl;
	ta->vtbl.AddRef(ta);
	ta->t = t;
	return ta;
}

static void freeTableAcc(struct tableAcc *ta)
{
	ta->t = NULL;
	ta->vtbl.Release(ta);
}

HANDLER(accessibilityHandler)
{
	if (uMsg != WM_GETOBJECT)
		return FALSE;
	if (wParam != OBJID_CLIENT)
		return FALSE;
	*lResult = LresultFromObject(&IID_IAccessible, wParam, t->ta);
	// TODO check *lResult
	return TRUE;
}