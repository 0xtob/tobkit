Summary: The Typesafe Signal Framework for C++
Name: libsigc++
Version: 2.2.3
Release: 1
License: LGPL
Group: System Environment/Libraries
Packager: Eric Bourque <ericb@computer.org>
URL: http://libsigc.sourceforge.net/
Source0: http://ftp.gnome.org/pub/GNOME/sources/libsigc++/2.0/%{name}-%{version}.tar.bz2
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root

%description

This library implements a full callback system for use in widget
libraries, abstract interfaces, and general programming. Originally
part of the Gtk-- widget set, %name is now a seperate library to
provide for more general use. It is the most complete library of its
kind with the ablity to connect an abstract callback to a class
method, function, or function object. It contains adaptor classes for
connection of dissimilar callbacks and has an ease of use unmatched by
other C++ callback libraries.

Package GTK-- (gtkmm), which is a C++ binding to the GTK+ library,
starting with version 1.1.2, uses %name.

Due to C++ ABI changes, this will only work with the gcc version which
the distribution was supplied with.  If you got your rpm from any
previous version, please rebuild from spec!

%package devel
Summary: Development tools for the Typesafe Signal Framework for C++
Group: Development/Libraries
Requires: %name = %version

%description devel
The %name-devel package contains the static libraries and header files
needed for development with %name.

%package examples
Summary: Examples and tests for the Typesafe Signal Framework for C++
Group: Development/Libraries
Requires: %name-devel = %version

%description examples
The %name-devel package contains source code of
example and test programs for %name.


%prep
%setup -q

%build
./configure --prefix=/usr
make

%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install
mkdir -p -m 755 $RPM_BUILD_ROOT/%{_libdir}/sigc++-2.0
cp -a examples tests $RPM_BUILD_ROOT/%{_libdir}/sigc++-2.0

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
%{_libdir}/libsigc*.so*
%doc /usr/share/doc/libsigc-2.0

%files devel
/usr/include/sigc++-2.0
%{_libdir}/pkgconfig/*
%{_libdir}/libsigc*.a
%{_libdir}/libsigc*.la
%dir %{_libdir}/sigc++-2.0
%dir %{_libdir}/sigc++-2.0/include
%{_libdir}/sigc++-2.0/include/sigc++config.h

%files examples
%{_libdir}/sigc++-2.0/examples
%{_libdir}/sigc++-2.0/tests

%changelog
* Tue Jun 29 2004 Eric Bourque <ericb@computer.org> - 2.0-1
- Initial build.

