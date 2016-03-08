QtPSD
=================================

PSD file loader for Qt. It is `psd.c <https://github.com/hkrn/psd.c/>`_ wrapper.

Install
--------------

This is a `qtpm <https://github.com/qtpm/qtpm>`_ package.

.. code-block:: bash

   $ qtpm get github.com/qtpm/QtPSD

Headers and a library file are installed under ``vendor/include`` and ``vendor/lib`` directory.

Example
--------------

.. code-block:: cpp

   #include <iostream>
   #include <QtPSD/QtPSD.h>
   #include <QImage>

   int main() {
       QImage image = QPSD::loadWholeImage("test.psd");
       std::cout << "width: " << image.width() << std::endl;
       std::cout << "height: " << image.height() << std::endl;
   }

Reference
--------------

* ``QImage QPSD::loadWholeImage(QString filepath)``

  Parse PSD file and returns single image.

Develop
--------------

``qtpm`` command helps your development.

.. code-block:: bash

   $ git clone git@github.com:qtpm/QtPSD.git
   $ cd QtPSD

   # Run the following command once if this package has required packages
   # -u updates modules they are already downloaded
   $ qtpm get [-u]

   # Build and run test
   $ qtpm test

   # Try install to ``vendor`` folder
   $ qtpm build


Folder Structure and Naming Convention
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: none

   + src/           // Header files under this folder will be published.
   |  |             // Don't add `main.cpp`. qtpm assumes this package is an application, not library.
   |  + private/    // Files under this folder will hide from outer modules.
   + test/          // Each _test.cpp file is built into executable and launched by qtpm test.
   |                // Use `qtpm add test`` to add test case.
   |                // Other .cpp files are used as utility code. They are linked to test modules.
   + doc/           // (not working yet) QDoc setting file and extra image files and so on.
   + html/          // (not working yet) HTML output of QDoc.
   + vendor/        // External libraries (source and binary)
   + build/         // Work folder.
   + CMakeExtra.txt // This file is included from created CMakeLists.txt.
                    // You can add any extra build options here.

Author
--------------

* shibukawa.yoshiki

License
--------------

The MIT License (MIT)

License for test data
--------------------------

Created by Mario Montagna. This image was downloaded from `here <http://freepsdfiles.net/holiday/saint-patrick-graphics-free-psd-set-1-wip>`_.

History
--------------

* 3/8/2016: First version 
