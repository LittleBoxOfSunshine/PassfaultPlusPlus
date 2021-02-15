# Passometer

Password policy is broken.  

### Password Analysis for the Real World

## FAQ

### Why Reinvent the Wheel?

`Ok, these criticisms of current industry practices are fair and the OWASP passfault solves them. Why create
another implementation?`

That's a fair question. While the OWASP project addresses the root issue, it's seen limited implementation
in industry because it's implementation in Java makes adoption more difficult. While Java is widely used in
production systems, there are also many teams using different software stacks, many in which the use of Java
is strictly prohibited. 

Moreover, this is a *big* ask. Passfault works because it treats password analysis as the *nuanced and complex
task that it is*. We contend that the status quo solution of naive complexity space dominates because it is
*theoretically* sound, easy to implement and easy to explain to users. Password rules can be enforced with
basic pattern finders, regex, or even just looping once through the string. Rolling your own code takes mere
minutes, and policy violations are easily communicable to the end user.

When we ask developers to utilize this model, we're not just asking them to install a new library. We're
asking them to fundamentally rethink their relationship with passwords, to take the time to learn and
understand our approach, to update their UI's, and to take the time (and potential support costs) to train 
their users on the very same. 

With any project, ease of adoption is critical to success. When the ask itself is so large, it's imperative
that the technical adoption be as simple as possible. Passometer is different because it produces a common
core artifact for analysis (the C++ library) and meets the developer in their software stack with concise
documentation on the methodology employed and, more importantly, guidance and samples for how they can
integrate the library into their existing projects including the UI. These challenges are even greater for
small teams who benefit from adoption the most given their limited (or even nonexistent) security budgets
and infrastructure.

Simply put, Passometer takes the excellent foundation laid by Passfault and builds a support ecosystem
around it to ensure the minimal possible friction in developer adoption. By lowering uptake costs we augment
their strong security fundamentals and make it viable for organizations to consider adopting their superior
approach to password analysis.

To accomplish this we produce:
- The core analysis library in C++ precompiled to all major platforms (Linux, Mac, Windows; x86, x64, and ARM64)
- Bindings or direct ports to the following with 1 step installs via their standard package managers
    - PHP (via PEAR)
    - Python (via Pip)
    - C# (via Nuget)
    - and more with community support (for Java we recommend using Passfault)
- A one page summary of the analysis algorithm, tailored to potential adopters to quickly understand why
they should uptake the library
- UI guidelines for integrating into a frontend with a best in class UX
- Reusable UI components in popular frameworks including
    - Bootstrap
    - React
    - Angular
