// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Delegate<void(const Params&)> bound-member glue for the
// minimap UI: vfunc_2 (invoke) / vfunc_3 (equals) of DelegateImpl<pair<C*, PMF>> for UIMinimapDialog (multiple
// inheritance: 16-byte PMF with a this-adjustment) and UIMinimapEntity (single inheritance), plus the two Call helpers.
// MS2-UNIT: unit_141a51d30
// MS2-RANGE: 0x141a51d30-0x141a51ec0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/ms2recover.h"

// Unit-local views of the two minimap UI classes: only the shape that fixes the PMF size is declared (the real
// class definitions live in the minimap UI units).
class Unk_MinimapBase { public: virtual ~Unk_MinimapBase(); };
class Unk_MinimapListener { public: virtual ~Unk_MinimapListener(); };
class UIMinimapDialog : public Unk_MinimapBase, public Unk_MinimapListener
{
public:
    void OnHandler(const Scaleform::GFx::FunctionHandler::Params& params);
};
class UIMinimapEntity : public Unk_MinimapBase
{
public:
    void OnHandler(const Scaleform::GFx::FunctionHandler::Params& params);
};

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Unk_MinimapDelegate;
typedef Unk_MinimapDelegate::DelegateImpl<std::pair<UIMinimapDialog*, void (UIMinimapDialog::*)(const Scaleform::GFx::FunctionHandler::Params&)> > Unk_MinimapDialogImpl;
typedef Unk_MinimapDelegate::DelegateImpl<std::pair<UIMinimapEntity*, void (UIMinimapEntity::*)(const Scaleform::GFx::FunctionHandler::Params&)> > Unk_MinimapEntityImpl;

template void Unk_MinimapDialogImpl::vfunc_2(const Scaleform::GFx::FunctionHandler::Params&);
template bool Unk_MinimapDialogImpl::vfunc_3(const Unk_MinimapDelegate::DelegateImplBase*) const;
template void Unk_MinimapEntityImpl::vfunc_2(const Scaleform::GFx::FunctionHandler::Params&);
template bool Unk_MinimapEntityImpl::vfunc_3(const Unk_MinimapDelegate::DelegateImplBase*) const;
