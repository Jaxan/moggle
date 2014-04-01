#
# Be sure to run `pod lib lint NAME.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#
Pod::Spec.new do |s|
  s.name             = "moggle"
  s.version          = "0.1.0"
  s.summary          = "A sexy C++11 OpenGL library."
  s.homepage         = "https://github.com/m-ou-se/moggle"
  s.license          = 'GPL'
  s.author           = { "Maurice Bos" => "m-ou.se@m-ou.se" }
  s.source           = { :git => "https://github.com/jaxan/moggle.git", :tag => "0.1.0" }

  s.source_files =  'src/**/*.{hpp,cpp}', 'include/**/*.hpp'
  s.public_header_files = 'include/**/*.hpp'
  s.header_mappings_dir = 'include'

  s.osx.frameworks = 'OpenGL'
  s.ios.frameworks = 'OpenGLES'
  s.compiler_flags = '-std=c++11 -stdlib=libc++'
end
