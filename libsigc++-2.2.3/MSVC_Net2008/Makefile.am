
BUILT_SOURCES = sigc++config.h sigc-2.0.rc

MAINTAINERCLEANFILES = $(built_sources)

DISTCLEANFILES = sigc++config.h

EXTRA_DIST=blank.cpp \
	   libsigc++2.vcproj libsigc++2.sln \
           sigc++config.h sigc-2.0.rc \
           tests/test_accumulated/test_accumulated.vcproj \
           tests/test_bind/test_bind.vcproj \
           tests/test_bind_return/test_bind_return.vcproj \
           tests/test_compatibility/test_compatibility.vcproj \
           tests/test_compose/test_compose.vcproj \
           tests/test_deduce_result_type/test_deduce_result_type.vcproj \
           tests/test_disconnect/test_disconnect.vcproj \
	   tests/test_disconnect_during_emit/test_disconnect_during_emit.vcproj \
           tests/test_exception_catch/test_exception_catch.vcproj \
           tests/test_functor_trait/test_functor_trait.vcproj \
           tests/test_hide/test_hide.vcproj \
           tests/test_lambda/test_lambda.vcproj \
           tests/test_mem_fun/test_mem_fun.vcproj \
           tests/test_ptr_fun/test_ptr_fun.vcproj \
           tests/test_retype/test_retype.vcproj \
           tests/test_retype_return/test_retype_return.vcproj \
           tests/test_signal/test_signal.vcproj \
           tests/test_size/test_size.vcproj \
           tests/test_slot/test_slot.vcproj \
           tests/test_trackable/test_trackable.vcproj


# Copy config file generated by the configure script. Dependency is 
# wht respect to the .h.in file, to prevent an error with 'make distcheck'.
# See http://sources.redhat.com/automake/automake.html#distcleancheck
  
sigc++config.h: $(top_srcdir)/sigc++config.h.in $(top_srcdir)/configure.ac
	cp -f $(top_builddir)/sigc++config.h $@
